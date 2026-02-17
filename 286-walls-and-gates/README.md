<!DOCTYPE html><html lang="en" class="dark-theme" data-critters-container><head>
    <meta charset="utf-8">
    <title>Islands and Treasure - NeetCode</title>
    <meta name="description" content="Leetcode 286. Walls And Gates

You are given a $m \times n$ 2D `grid` initialized with these three possible values:

1. `-1` - A water cell that *can not* be traversed.
2. `0` - A treasure chest.
3. `INF` - A land cell that *can* be traversed. We use the integer `2^31 - 1 = 2147483647` to represent `INF`.

Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest then the value should remain `INF`.

Assume the grid can only be traversed up, down, left, or right.

Modify the `grid` **in-place**.

**Example 1:**

```java
Input: [
  [2147483647,-1,0,2147483647],
  [2147483647,2147483647,2147483647,-1],
  [2147483647,-1,2147483647,-1],
  [0,-1,2147483647,2147483647]
]

Output: [
  [3,-1,0,1],
  [2,2,1,-1],
  [1,-1,2,-1],
  [0,-1,3,4]
]
```

**Example 2:**

```java
Input: [
  [0,-1],
  [2147483647,2147483647]
]

Output: [
  [0,-1],
  [1,2]
]
```
