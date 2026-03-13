A binary tree is a data-structure that has a root node, each node can have at most 2 children 
- Nodes can be terminal (leaves) and non-terminal
- terminal nodes are nodes that have no children

## Perfect Binary Tree
A special type of binary tree where all levels are completely filled. Each node has exactly 2 children, and all leaves are at the same level

- The no. nodes in any given level is $2^i$ where i is the level's index (zero based)
- The no. nodes in the entire tree is the summation of the no.nodes in each level

$$N_{total} = \sum_{i=0}^{n-1} 2^i = 1 + 2^1 + 2^2 + 2^3 ... + 2^{n-1} = 2^n - 1$$(geometric series where a = 1, r = 2)
where n is the no. levels, N is the total no. nodes in the entire tree

- no. terminal nodes is $2^{n-1}$ where n is no. levels (basically we are calculating the number of nodes in the last level, n-1 is the last level's index)
- no. non-terminal nodes is Total no. nodes - terminal nodes = $(2^n -1) - 2^{n-1} = 2^{n-1}$ (by factoring $2^{n-1}$)
- 