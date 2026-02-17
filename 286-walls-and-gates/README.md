<h2><a href="https://leetcode.com/problems/walls-and-gates">Walls And Gates</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' />
<hr><p>You are given an <code>m x n</code> grid <code>rooms</code> initialized with these three possible values:</p>

<ul>
<li><code>-1</code>: A wall or an obstacle.</li>
<li><code>0</code>: A gate.</li>
<li><code>INF</code>: Infinity means an empty room. We use the value <code>2<sup>31</sup> - 1 = 2147483647</code> to represent <code>INF</code>.</li>
</ul>

<p>Fill each empty room with the distance to its <em>nearest gate</em>. If it is impossible to reach a gate, it should be filled with <code>INF</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> grid = [
[2147483647,-1,0,2147483647],
[2147483647,2147483647,2147483647,-1],
[2147483647,-1,2147483647,-1],
[0,-1,2147483647,2147483647]
]
<strong>Output:</strong> [
[3,-1,0,1],
[2,2,1,-1],
[1,-1,2,-1],
[0,-1,3,4]
]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> grid = [[0,-1],[2147483647,2147483647]]
<strong>Output:</strong> [[0,-1],[1,2]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
<li><code>m == grid.length</code></li>
<li><code>n == grid[i].length</code></li>
<li><code>1 &lt;= m, n &lt;= 250</code></li>
<li><code>grid[i][j]</code> is <code>-1</code>, <code>0</code>, or <code>2<sup>31</sup> - 1</code>.</li>
</ul>
