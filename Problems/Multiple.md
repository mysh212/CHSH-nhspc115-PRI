## **G. 乘法** ***<font color = '#AAAAAA'> Multiple </font>***

`time limit` 1s
`memory limit` 64MB

### ***Statement***

***ysh*** 最近正在 ***UCKN*** 大學修習微積分，數學系的 **格子教授** 在講台上侃侃而談，從 **黎曼和** 、 ***Jacobian*** 、***Shell Method*** 到 ***L'Hôpital's rule*** ，每樣都讓 ***ysh*** 又愛又恨。

而明天就是期末考的日子了， ***ysh*** 正在努力複習這些觀念，並期待能夠考個比 ***Mingyee*** 高的成績。

$$
\displaystyle \lim_{x \rightarrow c} \frac{f(x)}{g(x)} = \lim_{x \rightarrow c} \frac{f'(x)}{g'(x)}_{...\text{L'Hôpital's rule}}
$$

但期末考當天， ***ysh*** 拿到考卷時傻眼了，考卷只有一題：

> 請輸出 $\overbrace{aa...a}^{n \text{個}} \times \underbrace{bb...b}_{m \text{個}}$ 。
> 
> 舉個例子，當 $(a, b, n, m) = (1, 2, 4, 5)$ 時，需要輸出 $1111 \times 22222$ 。

你可以幫他寫一個程式來完成這件事嗎？

<div style = 'width: 100vw; text-align: center'>
    <img alt = 好看梗圖 src = 'imgs/Multiple/SJnZdhLDzx.png' height = 550px />
</div>

<div class = page />

### ***Input***

$a$ $b$ $n$ $m$

### ***Output***

$Ans$

### ***Sample Input***

```
1 2 4 5
```

### ***Sample Output***

```
24688642
```

### ***Note***

 - $1 \leq n, m \leq 10 ^ 3$
 - $1 \leq a, b \leq 9$

### ***Subtask***

 - ***subtask1***: $5\\%$ $n \leq 7, m  = 1, a, b \leq 2$
 - ***subtask2***: $46\\%$ $m  = 1$
 - ***subtask3***: $49\\%$ ***As statement***