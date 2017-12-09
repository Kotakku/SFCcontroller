# SFCcontroller-with-Arduino


[SFC controller library for Arduino]

スーパーファミコンのコントローラーをArduinoで使うためのライブラリです。
(※スーパーファミコンミニには対応していません)

●インストール

展開した SFCcontroller フォルダを下記のフォルダに
置くだけでインストールできます。

	マイドキュメント\Arduino\libraries\

置いた後、Arduino IDE のメニュー [ファイル] → [スケッチの例] に
SFCcontroller が現れることを確認してください。

●使い方

```
  #include <StdSFCcontroller.h>

  //インスタンス生成
  //この時コントローラーと接続する3本の信号線のピン番号を指定します
  //この場合はクロックピンに2番、PSピンに3番、データピンに4番を指定します
  //ピンの接続については下で説明
  SFCcontroller SFC(2, 3, 4);

  void setup()
  {

  }

  void loop()
  {
    //ボタンの状態更新(必須)
    updateButtonState();
  }
```

●その他関数
  bool getButtonPress(uint8_t button);
    指定されたボタンが押されていればtrueを返す
  bool getButtonClick(uint8_t button);
    指定されたボタンが押されたらtrueを返す

  なお、引数に指定するボタンの識別子はヘッダファイル内で下のように定義してあります
  enum buttoneNum
  {
    BUTTON_B,
    BUTTON_Y,
    BUTTON_SELECT,
    BUTTON_START,
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_A,
    BUTTON_X,
    BUTTON_L,
    BUTTON_R
  };

●プログラム例
  Click_test
    getButtonClick関数のデモ
  Press_test
    getButtonPress関数のデモ
  AllButton_test
    上二つの関数の引数に変数を与えるデモ

●コントローラーのピンの名前と大まかな役割
   ┌----------┬--------
   | V C P D1 | D2 S G |
   └----------┴--------┘
   V  = Vcc
   C  = Clock (input to SFCcontroller)
   P  = PS    (input to SFCcontroller)
   D1 = Data1 (output from SFCcontroller)
   D2 = Data2 (output from SFCcontroller)
   S  = Select (?)
   G  = GND

   なお、このライブラリではD2ピンとSピンは使うことを想定していません

●その他
  実際に動かしてみたところ、チャタリングが激しいためクリックなどを使うときはその分を考慮して使うようにしてください。

作者：小田島 拓海 - Takumi Odashima
