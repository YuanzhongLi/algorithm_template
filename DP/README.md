### get_largest_rect
![](./img/get_largest_rect_001.png)

### 復習
#### abc130E
数え上げのときの注意

#### 耳DP
主に[l, r]での状態遷移を扱う
dp[i][3]
iまでに
- まだ左端を選択していない状態 (状態 0)
- 左端は選択済みだけど右端は選択していない状態 (状態 1)
- 右端も選択済みの状態 (状態 2)
