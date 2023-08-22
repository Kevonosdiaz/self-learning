package leetcode

import "strconv"

func isValidSudoku(board [][]byte) bool {
	rows := map[int]int{}
	cols := map[int]int{}
	grids := make([][]int, 3)

	// Using prime method of duplicate checking
	primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23}
	grids[0] = []int{1, 1, 1}
	grids[1] = []int{1, 1, 1}
	grids[2] = []int{1, 1, 1}

	for i := range board {
		for j := range board[0] {
			if board[i][j] == '.' {
				continue
			}

			pos, _ := strconv.Atoi(string(board[i][j]))

			if rows[pos] == 0 {
				rows[pos] = 1
			}
			if cols[pos] == 0 {
				cols[pos] = 1
			}

			if rows[pos]%primes[i] == 0 ||
				cols[pos]%primes[j] == 0 ||
				grids[i/3][j/3]%primes[pos-1] == 0 {
				return false
			}

			rows[pos] *= primes[i]
			cols[pos] *= primes[j]
			grids[i/3][j/3] *= primes[pos-1]
		}
	}

	return true

}
