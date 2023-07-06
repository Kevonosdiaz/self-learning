import java.util.HashSet;
import java.util.Set;
public class Leetcode217 {
	/**
	 * Takes in an input integer array
	 * If any value appears at least twice, then returns true
	 * Otherwise return false
	 * @param nums integer array
	 * @return
	 */
	public static boolean containsDuplicate(int[] nums) {
		Set<Integer> hs = new HashSet<Integer>(); 
		boolean bool;
		// Use a HashSet to check membership of duplicates within nums
        for (int i=0; i < nums.length; i++) {
        	bool = hs.add(nums[i]);
        	if (bool == false) {
        		return true;
        	}
        }
		return false;
    }
}
