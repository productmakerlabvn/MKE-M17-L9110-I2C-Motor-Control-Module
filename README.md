# Mạch điều khiển động cơ MKE-M10 I2C motor control module

![](/image/MKE_M10_1.jpg)

## Giới thiệu

Mạch điều khiển động cơ MKE-M10 I2C motor control module được sử dụng để điều khiển cùng lúc 2 x động cơ DC và 2 x động cơ RC Servo trong các ứng dụng điều khiển robot, xe tự hành, mạch sử dụng giao tiếp I2C nên dễ dàng kết nối và sử dụng với chỉ 2 chân giao tiếp I2C là SDA (data) và SCL (clock).

Mạch điều khiển động cơ MKE-M10 I2C motor control module thuộc hệ sinh thái phần cứng Robotics MakerEdu với chuẩn kết nối connector XH2.54, cảm biến có thể sử dụng trực tiếp an toàn với các mạch điều khiển trung tâm giao tiếp ở cả hai mức điện áp 3.3VDC / 5VDC như: Arduino, Raspberry Pi, Jetson Nano, Micro:bit,....

> **Cảnh báo:**  
Nếu sử dụng động cơ RC Servo 5VDC công suất lớn có thể gây sụt áp, quá tải, chạy không ổn định, Quý Khách cần mua thêm Mạch cấp nguồn bổ sung MKE-M12 5VDC 5A power supply module với khả năng cấp nguồn 5VDC với dòng điện cung cấp tối đa lên đến 5A cho cổng POWER+.

## Thông số kỹ thuật

- Điện áp cấp cho mạch hoạt động: nguồn 5VDC từ cổng POWER+ (IN)
- Điện áp cấp cho động cơ hoạt động VM (V_Motor): nguồn VIN 6~12VDC từ cổng POWER+ (IN)
- Dòng cấp tối đa cho mỗi động cơ: 1.2A
- Chuẩn giao tiếp: Digital I2C
- Các chân giao tiếp: SDA (Serial Data) / SCL (Serial Clock)
- Điện áp giao tiếp: TTL 3.3/5VDC
- Địa chỉ I2C: 64~68 địa chỉ (có thể cài đặt hoặc thay đổi trong code)
- Điều khiển được 2 động cơ DC và 2 động cơ RC Servo cùng lúc.
- Sử dụng trực tiếp an toàn với các mạch điều khiển trung tâm giao tiếp ở cả hai mức điện áp 3.3VDC và 5VDC như: Arduino, Raspberry Pi, Jetson Nano, Micro:bit,....
- Bổ sung thêm các thiết kế ổn định, chống nhiễu.
- Chuẩn kết nối:
- 2 x Conector XH2.54 4Pins (cổng I2C và POWER+ (IN))
- 2 x Conector Domino 2P (MotorA và MotorB)
- 2 x Male Header 3P 2.54mm (RC Servo S1 và S2)
- Thuộc hệ sinh thái phần cứng Robotics MakerEdu, tương thích tốt nhất khi sử dụng với các mạch điều khiển trung tâm của MakerEdu và MakerEdu Shield.

## Kích thước

![](/image/MKE_M10_2.jpg)

## Các chân tín hiệu

![](/image/MKE_M10_3.jpg)
<table><thead>
  <tr>
    <th>MKE-M10 / Cổng tín hiệu I2C</th>
    <th>Ghi chú</th>
  </tr></thead>
<tbody>
  <tr>
    <td>GND</td>
    <td>Chân cấp nguồn âm 0VDC</td>
  </tr>
  <tr>
    <td>NC</td>
    <td>Không kết nối (not connect)</td>
  </tr>
  <tr>
    <td>SDA</td>
    <td>Chân tín hiệu I2C Serial Data</td>
  </tr>
  <tr>
    <td>SCL</td>
    <td>Chân tín hiệu I2C Serial Clock</td>
  </tr>
</tbody>
</table>

<table><thead>
  <tr>
    <th>MKE-M10 / Cổng cấp nguồn Power+ (IN)</th>
    <th>Ghi chú</th>
  </tr></thead>
<tbody>
  <tr>
    <td>GND</td>
    <td>Chân cấp nguồn âm 0VDC</td>
  </tr>
  <tr>
    <td>VM (6~12V)</td>
    <td>Chân cấp nguồn 6~12VDC cho động cơ hoạt động<br>(lấy từ nguồn VIN của cổng POWER+)</td>
  </tr>
  <tr>
    <td>5V</td>
    <td>Chân nguồn 5VDC cấp cho mạch hoạt động<br>(lấy từ nguồn 5VDC của cổng POWER+)</td>
  </tr>
  <tr>
    <td>NC</td>
    <td>Không kết nối (not connect)</td>
  </tr>
</tbody>
</table>

<table><thead>
  <tr>
    <th>MKE-M10 / Cổng cấp nguồn Power+ (IN)</th>
    <th>Ghi chú</th>
  </tr></thead>
<tbody>
  <tr>
    <td>GND</td>
    <td>Chân cấp nguồn âm 0VDC</td>
  </tr>
  <tr>
    <td>VM (6~12V)</td>
    <td>Chân cấp nguồn 6~12VDC cho động cơ hoạt động<br>(lấy từ nguồn VIN của cổng POWER+)</td>
  </tr>
  <tr>
    <td>5V</td>
    <td>Chân nguồn 5VDC cấp cho mạch hoạt động<br>(lấy từ nguồn 5VDC của cổng POWER+)</td>
  </tr>
  <tr>
    <td>NC</td>
    <td>Không kết nối (not connect)</td>
  </tr>
</tbody>
</table>

## Hướng dẫn sử dụng

### Các thiết bị sử dụng trong bài hướng dẫn

#### Arduino

- [Mạch Vietduino Uno (Arduino Uno Compatible)](https://www.makerlab.vn/vuno)
- [Mạch MakerEdu Shield for Vietduino](https://www.makerlab.vn/vietduinosd)
- [Mạch màn hình MKE-M07 LCD1602 I2C Display Module](https://www.makerlab.vn/mkem07)
- [Động cơ RC Servo 9G](https://hshop.vn/dong-co-rc-servo-9g)

#### mBlock

- [Mạch MakerEdu Creator (Arduino Uno Compatible)](https://www.makerlab.vn/creator)
- [Mạch màn hình MKE-M07 LCD1602 I2C Display Module](https://www.makerlab.vn/mkem07)
- [Động cơ RC Servo 9G](https://hshop.vn/dong-co-rc-servo-9g)

#### Micro:bit:

- [Mạch Micro:bit V2](https://hshop.vn/products/kit-hoc-lap-trinh-stem-cho-tre-em-micro-bit-v2) hoặc các phiên bản tương thích.
- [Mạch MakerEdu Shield for Micro:bit](https://www.makerlab.vn/microbitsd)
- [Mạch màn hình MKE-M07 LCD1602 I2C Display Module](https://www.makerlab.vn/mkem07)
- [Động cơ RC Servo 9G](https://hshop.vn/dong-co-rc-servo-9g)

### Hướng dẫn sử dụng với Arduino (Code C)

[Hướng dẫn cài đặt phần mềm, nạp chương trình, cài đặt bộ thư viện Arduino cơ bản.](https://github.com/makerlabvn/Arduino-Vietduino)

- Tải và cài đặt [phần mềm Arduino tại đây.](https://www.arduino.cc/en/software)
- Trong Tools / Library Manager, tìm và cài đặt bộ thư viện tổng hợp "MAKERLABVN" by MakerLab.vn
- Mở chương trình mẫu "MKE_M10_I2C_Motor_LCD_Serial.ino" tại File / Examples / MAKERLABVN / Module / MKE_M10_I2C_Motor_LCD_Serial hoặc [tải chương trình mẫu tại đây](/arduino)
- Chọn board là Arduino Uno (mạch Vietduino Uno tương thích với Arduino Uno), chọn đúng cổng COM Port của mạch và tiến hành nạp chương trình.
- Kết nối mạch Vietduino Uno với MakerEdu Shield, kết nối module MKE-M10 vào cổng [I2C] và màn hình LCD vào cổng [I2C] trên MakerEdu Shield, kết nối động cơ RC Servo vào module MKE-M10, cấp nguồn qua cổng USB của Vietduino Uno để thấy chương trình hoạt động.

### Hướng dẫn lập trình với mBlock (kéo thả khối)

[Hướng dẫn cài đặt phần mềm, nạp chương trình, cài đặt Extension mBlock cơ bản.](https://github.com/makerlabvn/mBlock-MakerEdu-Creator)

- Tải và cài đặt phần mềm mBlock 5 ([Windows](https://www.mediafire.com/file/ma55iajd7glwmbo/%255BMakerLab.vn%255D_mBlock_V5.4.3_for_Windows.zip/file) / [Mac Intel](https://www.mediafire.com/file/pjfngy6d7ktb55f/%255BMakerLab.vn%255D_mBlock_V5.4.3_for_Mac_Intel.zip/file) / [Mac M1M2](https://www.mediafire.com/file/mfdkgpgnpa7uv2s/%255BMakerLab.vn%255D_mBlock_V5.4.3_for_Mac_M1M2.zip/file))
- Thêm Device "MakerEdu Creator" by MakerEduVN
- Thêm Extension "Upload Mode Broadcast" by mBlock Official
- Thêm Extension "MakerEdu Hardware" by MakerEduVN
- Mở [chương trình mẫu tại đây](/mBlock5), kết nối MakerEdu Creator với máy tính và nạp chương trình.
- kết nối module MKE-M10 vào cổng [I2C] và màn hình LCD vào cổng [I2C] trên MakerEdu Creator, kết nối động cơ RC Servo vào module MKE-M10, cấp nguồn qua cổng USB của MakerEdu Creator để thấy chương trình hoạt động.

### Hướng dẫn lập trình với Micro:bit (kéo thả khối)

[Hướng dẫn nạp chương trình, cài đặt Extension Micro:bit cơ bản.](https://github.com/makerlabvn/MakeCode-microbit)

- Khởi động phần mềm MakeCode tại: [https://makecode.microbit.org/](https://makecode.microbit.org/)
- Chọn My Projects / Import / Import URL theo đường link của chương trình mẫu: [https://github.com/devmakerlabvn/makecode-mke-s01-ultrasonic-distance-sensor](https://github.com/devmakerlabvn/makecode-mke-s01-ultrasonic-distance-sensor)
- Kết nối Micro:bit với máy tính và nạp chương trình.
- Kết nối mạch Micro:bit với MakerEdu Shield, và màn hình LCD vào cổng [I2C] trên MakerEdu Shield, **cấp nguồn qua cổng USB của MakerEdu Shield** để thấy chương trình hoạt động.

## Hỗ trợ và liên hệ

- Website: [https://www.makerlab.vn/](https://www.makerlab.vn/)
- Facebook: [https://www.facebook.com/makerlabvn](https://www.facebook.com/makerlabvn)

## Nhà phân phối

- Các bạn có thể mua sản phẩm của MakerLab tại các [Nhà Phân Phối.](https://www.makerlab.vn/distributor/)
