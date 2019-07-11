## 使用
> #### 开发用户
>>微信跳一跳android端外挂。基于vs2017 + QT + Opencv，所以请自行配置开发环境。
> #### 普通用户
>>1.只需下载 [戳我下载](https://github.com/qianmang2/WXJump/raw/master/普通用户只需下载我.rar)</br>
>>2.用USB线连接手机与电脑。</br>
>>3.在手机设置->关于手机->版本号 处连续点击7次显示出 开发者模式 选项，然后进入 开发者模式 里打开USB调试开关


## 原理
1.用android adb命令进行截图存储到手机，然后用adb命令导出图像到程序目录。</br>
2.使用opencv提供的 matchtemplate函数 先找出棋子位置位值，然后计算棋子底部的中心点。</br>
3.使用opencv提供的cvtColor canny等函数处理后 获取图像的边缘（此时也就时二值图）。</br>
4.然后从原图像的高度的25% 并且除去棋子宽度区域（也就是不查找棋子宽度的区域像素） 开始上到下查找图像最先出现的白色像素点。</br>
5.查找到最高点后，判断这个最高点在棋子的左边还是棋子的右边，并记录下。</br>
6.若在左边，则从二值图最左边向最高点处查找，若在右边，则从二值图最右边处向最高点处查找最先出现的白点。</br>
7.然后最高点的x值和另一个点的y值就形成了下一个目标点了。</br>
8.根据两点算得两点之间的距离乘以一个系数（可以慢慢尝试这个系数）就可以获得按压时间了。</br>

## adb命令
adb截图：`adb shell /system/bin/screencap -p /sdcard/screenshot.png`</br>
adb导出图像命令：  `adb pull /sdcard/screenshot.png ./gamescreenshot.png`</br>
adb模拟按压命令:   `adb shell input swipe 200 300 400 500 2000`  (200：第一个点的x坐标 300：第一个点的y坐标   400：第二个点的x坐标  500：第二个点的y坐标 2000：按压时长单位毫秒)</br>


## 效果图：
![外挂客户端截图](https://github.com/qianmang2/WXJump/raw/master/image/clientImage.png "电脑端辅助截图")
![手机端截图](https://github.com/qianmang2/WXJump/raw/master/image/screencap.png "手机端游戏截图")

```mermaid
flowchat
st=>start: 开始
e=>end: 结束
op=>operation: 我的操作
cond=>condition: 确认？

st->op->cond
cond(yes)->e
cond(no)->op
```
