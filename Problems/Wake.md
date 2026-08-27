## **A. 裝弱** ***<font color = '#AAAAAA'> Wake </font>***

`time limit` 1s
`memory limit` 256MB

### ***Statement***

大家都知道 ***HARC*** 裡的人最愛裝弱了，像是 ***Willy, MelonHiler, Mingyee*** 等都是裝弱老手。

而經過 ***ysh*** 深入研究後，他決定將這種現象命名為 $\text{Weak} + \text{Fake} = \text{Wake}$

由於亂象頻傳， ***ysh*** 決定出手解決亂象。

首先他給大家一個編號，稱為 $i,\ 1 \leq i \leq n$ ，而每個人有一次說出證詞的機會。

而證詞只可以是以下兩種:

 - 「我覺得編號 $j,\ 1 \leq j \leq n$ 的人在裝弱。」
 - 「我覺得編號 $j,\ 1 \leq j \leq n$ 的人不會裝弱。」

而因為裝弱的人都會到處膜拜別人(如下圖)，因此可以認定裝弱的人說出來的話都恰好與事實相反。

由於人數太多， ***ysh*** 便請了顧問 ***Amberela*** 協助蒐集證詞。

但因為 ***Amberela*** 蒐集的資料疑似不小心被 ***Mingyee*** 竄改了，而 ***ysh*** 又很弱，所以他想請你寫一支程式幫助他看看 ***Amberela*** 帶回來的證詞是否合理可信。

![圖片](imgs/Wake/rJgpicIvGg.png)

<div class = page />

### ***Input***

$n$
$o_1$ $p_1$
$o_2$ $p_2$
...
$o_n$ $p_n$

總共有 $n$ 個人，因此共有 $n$ 筆資料。

而第 $i,\ 1 \leq i \leq n$ 個人說出的證詞記為如下:

若 $p_i = 1$ ，代表第 $i$ 個人的證詞為 **「我覺得編號 $o_i$ 的人在裝弱」**；
而若 $p_i = 0$ ，則表示 **「我覺得編號 $o_i$ 的人不會裝弱」** 。

### ***Output***

$Ans$

如果所有人的證詞合理，看起來沒有被 ***Mingyee*** 竄改的話，請輸出***Yes*** ，否則為 ***No*** 。

### ***Sample Input 1***

```
3
2 1
3 1
1 1
```

### ***Sample Output 1***

```
No
```

<div class = page />

### ***Sample Input 2***

```
7
5 0
3 1
5 1
3 1
1 0
4 0
1 1
```

### ***Sample Output 2***

```
Yes
```

### ***Note***

 - $2 \leq n \leq 4 \times 10 ^ 5$
 - $1 \leq o_i \leq n,\ \forall\ 1 \leq i \leq n$
 - $p_i \in \\{0, 1\\},\ \forall\ 1 \leq i \leq n$
 - $o_i \not = i,\ \forall 1 \leq i \leq n$

### ***Subtask***

 - ***subtask1***: $3\\%$ $p_i = 0,\ \forall 1 \leq i \leq n$
 - ***subtask2***: $6\\%$ $p_i = 1,\ \forall 1 \leq i \leq n$
 - ***subtask3***: $21\\%$ $n \leq 20$
 - ***subtask4***: $27\\%$ $n \leq 40$
 - ***subtask5***: $17\\%$ $n \leq 10 ^ 3$
 - ***subtask6***: $26\\%$ ***As statement***