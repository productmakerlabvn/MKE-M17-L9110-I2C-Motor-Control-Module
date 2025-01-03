# Mạch điều khiển động cơ MKE-M17 L9110 I2C motor control module

<!-- ![](/image/MKE_M10_1.jpg) -->

## Giới thiệu

Mạch điều khiển động cơ MKE-M17 L9110 I2C motor control module được sử dụng để điều khiển cùng lúc 2 x động cơ DC và 2 x động cơ RC Servo trong các ứng dụng điều khiển robot, xe tự hành, mạch sử dụng giao tiếp I2C nên dễ dàng kết nối và sử dụng với chỉ 2 chân giao tiếp I2C là SDA (data) và SCL (clock).

Mạch điều khiển động cơ MKE-M17 L9110 I2C motor control module thuộc hệ sinh thái phần cứng Robotics MakerEdu với chuẩn kết nối connector XH2.54, cảm biến có thể sử dụng trực tiếp an toàn với các mạch điều khiển trung tâm giao tiếp ở cả hai mức điện áp 3.3VDC / 5VDC như: Arduino, Raspberry Pi, Jetson Nano, Micro:bit,....

## Thông số kỹ thuật

- Điện áp cấp cho mạch hoạt động: nguồn 5VDC từ cổng I2C
- Điện áp cấp cho động cơ hoạt động VM (V_Motor): 5~10VDC
- Dòng cấp tối đa cho mỗi động cơ: 800mA
- Chuẩn giao tiếp: Digital I2C
- Các chân giao tiếp: SDA (Serial Data) / SCL (Serial Clock)
- Điện áp giao tiếp: TTL 3.3/5VDC
- Địa chỉ I2C: 64~68 địa chỉ (có thể cài đặt hoặc thay đổi trong code)
- Điều khiển được 2 động cơ DC và 2 động cơ RC Servo cùng lúc.
- Sử dụng trực tiếp an toàn với các mạch điều khiển trung tâm giao tiếp ở cả hai mức điện áp 3.3VDC và 5VDC như: Arduino, Raspberry Pi, Jetson Nano, Micro:bit,....
- Bổ sung thêm các thiết kế ổn định, chống nhiễu.
- Chuẩn kết nối:
  - 1 x Conector XH2.54 4Pins (cổng I2C)
  - 2 x Conector Domino 2P (MotorA và MotorB)
  - 2 x Male Header 3P 2.54mm (RC Servo S1 và S2)
- Thuộc hệ sinh thái phần cứng Robotics MakerEdu, tương thích tốt nhất khi sử dụng với các mạch điều khiển trung tâm của MakerEdu và MakerEdu Shield.

## Kích thước

<!-- ![](/image/MKE_M10_2.jpg) -->

## Các chân tín hiệu

<!-- ![](/image/MKE_M10_3.jpg) -->
<table><thead>
  <tr>
    <th>MKE-M17 / Cổng tín hiệu I2C</th>
    <th>Ghi chú</th>
  </tr></thead>
<tbody>
  <tr>
    <td>GND</td>
    <td>Chân cấp nguồn âm 0VDC</td>
  </tr>
  <tr>
    <td>5V</td>
    <td>Chân cấp nguồn dương 5VDC</td>
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
    <th>MKE-M17 / Cổng cấp nguồn VM</th>
    <th>Ghi chú</th>
  </tr></thead>
<tbody>
  <tr>
    <td>VM (5~10V)</td>
    <td>Chân cấp nguồn 5~10VDC cho động cơ hoạt động<br>(nếu kết nối jumber vào chân 5V thì driver lấy nguồn 5V nuôi động cơ. nếu lấy nguồn ngoài thì nối +VDC vào chân VMM, 0VDC vào chân GND)</td>
  </tr>
  <tr>
    <td>5V</td>
    <td>Chân nguồn 5VDC</td>
  </tr>
</tbody>
</table>

## Hướng dẫn sử dụng

### Hướng dẫn sử dụng với Arduino (Code C)
- Thiết bị sử dụng:
  - 1 x [Mạch Vietduino Uno (Arduino Uno Compatible)](https://www.makerlab.vn/vuno)
  - 2 x [Động cơ RC Servo 9G](https://hshop.vn/dong-co-rc-servo-9g)
  - 2 x [Động cơ DC giảm tốc V1 Dual Shaft Plastic Geared TT Motor](https://hshop.vn/dong-co-dc-giam-toc-v1-dual-shaft-plastic-geared-tt-motor)
- Sơ đồ kết nối:
  ![](/image/circuit.png)
- Chương trình mẫu: [tải chương trình mẫu tại đây](/arduino)

### Hướng dẫn lập trình với mBlock (kéo thả khối)
- Thiết bị sử dụng:
- Sơ đồ kết nối:
- Chương trình mẫu:

### Hướng dẫn lập trình với Micro:bit (kéo thả khối)
- Thiết bị sử dụng:
- Sơ đồ kết nối:
- Chương trình mẫu:

## Hỗ trợ và liên hệ

- Website: [https://www.makerlab.vn/](https://www.makerlab.vn/)
- Facebook: [https://www.facebook.com/makerlabvn](https://www.facebook.com/makerlabvn)

## Nhà phân phối

- Các bạn có thể mua sản phẩm của MakerLab tại các [Nhà Phân Phối.](https://www.makerlab.vn/distributor/)
