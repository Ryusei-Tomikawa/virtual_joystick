# virtual_joystick
これは、仮想ジョイスティックが使用できるリポジトリです。

# 動作方法
ビルドはたぶんできるはずなので、ご自分でやってください。エラーはないはずです。

仮想ジョイスティックを使用する際は２つノードを起動する必要があります。（別に１つのlaunchに書けばいい話なんやけど）
`$ rosrun joy_teleop joy_teleop_node/`

`$ rosrun rqt_virtual_joy rqt_virtual_joy/`

これをやればGUIがたちあがるはず！
あとは、topic名が"/joy"になっており、publishにチェックをすれば基本的にはOK!
各々、Hzはお好きにどうぞ〜！

