fn two_sum(nums []int, target int) []int {
    mut indices := []int
    mut num_to_index := map[string]int{}
    for i, n in nums {
        ns := '$n'
        if ns in num_to_index {
            indices << num_to_index[ns]
            indices << i
            break
        } else {
            t := target - n
            num_to_index['$t'] = i
        }
    }
    return indices
}

fn test_two_sum() {
    assert two_sum([2, 7, 11, 15], 9).str() == '[0, 1]'
    assert two_sum([2, 7, 4, 5, 6, 11, 15], 20).str() == '[3, 6]'
}

test_two_sum()
