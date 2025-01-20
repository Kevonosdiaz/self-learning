#include <hip/hip_runtime_api.h>
#include <hip/hip_vector_types.h>
#include <iostream>
#include <rocfft/rocfft.h>
#include <vector>

// Example based on https://rocm.docs.amd.com/projects/rocFFT/en/latest/how-to/working-with-rocfft.html

int main()
{
    // std::vector<float2> cx = {{0, 1}, {10, 12}, {4.5578, -7.92125}, {0.000123, -0.0009783}};

    // Setup rocFFT and input data
    std::vector<float2> cx;
    float               tmp1, tmp2;
    while(std::cin >> tmp1 >> tmp2)
    {
        cx.push_back({tmp1, tmp2});
    }

    rocfft_setup();
    size_t  N         = 4;
    size_t  num_bytes = N * sizeof(float2);
    float2* x;
    hipMalloc(&x, num_bytes);
    hipMemcpy(x, cx.data(), num_bytes, hipMemcpyHostToDevice);

    // rocFFT plan
    rocfft_plan plan   = nullptr;
    size_t      length = N;
    rocfft_plan_create(&plan,
                       rocfft_placement_inplace,
                       rocfft_transform_type_complex_forward,
                       rocfft_precision_single,
                       1,
                       &length,
                       1,
                       nullptr);

    // Check if work buf needed
    size_t work_buf_size = 0;
    rocfft_plan_get_work_buffer_size(plan, &work_buf_size);
    void*                 work_buf = nullptr;
    rocfft_execution_info info     = nullptr;
    if(work_buf_size)
    {
        rocfft_execution_info_create(&info);
        hipMalloc(&work_buf, work_buf_size);
        rocfft_execution_info_set_work_buffer(info, work_buf, work_buf_size);
    }

    rocfft_execute(plan, (void**)&x, nullptr, info);
    hipDeviceSynchronize();

    if(work_buf_size)
    {
        hipFree(work_buf);
        rocfft_execution_info_destroy(info);
    }

    rocfft_plan_destroy(plan);
    std::vector<float2> host_output(N);
    hipMemcpy(host_output.data(), x, num_bytes, hipMemcpyDeviceToHost);
    for(auto& cmplx : host_output)
    {
        std::cout << "(" << cmplx.x << "," << cmplx.y << ") ";
    }
    std::cout << std::endl;

    hipFree(x);
    rocfft_cleanup();
    return 0;
}
