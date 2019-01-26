use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut num_to_index = HashMap::new();
        let mut pair_indices = Vec::new();
        for (i, n) in nums.iter().enumerate() {
            if let Some(&j) = num_to_index.get(&(target - n)) {
                pair_indices.push(j);
                pair_indices.push(i as i32);
                break;
            } else {
                num_to_index.insert(n, i as i32);
            }
        }
        pair_indices
    }
}

struct Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(Solution::two_sum(vec!(2, 7, 11, 15), 9), vec!(0, 1));
        assert_eq!(Solution::two_sum(vec!(2, 7, 4, 5, 6, 11, 15), 20), vec!(3, 6));
    }
}