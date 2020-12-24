// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result = vec![];

        let mut stacks: Vec<Vec<Rc<RefCell<TreeNode>>>> = vec![Vec::new(), Vec::new()];
        if let Some(root) = root {
            stacks[0].push(root);
        }

        let mut i = 0;
        while !stacks[i & 1].is_empty() {
            let mut r = vec![];
            while let Some(t) = stacks[i & 1].pop() {
                r.push(t.borrow().val);
                if i & 1 != 1 {
                    if let Some(ref left) = t.borrow().left {
                        stacks[(i + 1) & 1].push(Rc::clone(left));
                    }
                    if let Some(ref right) = t.borrow().right {
                        stacks[(i + 1) & 1].push(Rc::clone(right));
                    }
                } else {
                    if let Some(ref right) = t.borrow().right {
                        stacks[(i + 1) & 1].push(Rc::clone(right));
                    }
                    if let Some(ref left) = t.borrow().left {
                        stacks[(i + 1) & 1].push(Rc::clone(left));
                    }
                }
            }
            result.push(r);
            i += 1;
        }

        result
        //            3
        //         9     20
        //       1   2  15  7
        //     x   y   z  k
        // 3, 20 9, 1 2 15 7, k z y x
        //    s1:3        s2:
        // 3  s1:         s2:9 20
        // 20 s1:7,15     s2:9
        // 9  s1:7,15,2,1 s2:
        // 1  s1:7,15,2   s2:x,y
        // 2  s1:7,15     s2:x,y
        // 15 s1:7        s2:x,y,z,k
        // 7  s1:         s2:x,y,z,k
        // k
    }
}

struct Solution {}
