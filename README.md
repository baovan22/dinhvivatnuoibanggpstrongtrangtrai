HỆ THỐNG ĐỊNH VỊ VẬT NUÔI TRONG TRANG TRẠI

📝 Giới thiệu
Hệ thống định vị vật nuôi bằng GPS là một giải pháp công nghệ giúp theo dõi vị trí của gia súc, gia cầm trong khu vực trang trại một cách chính xác và liên tục. Thiết bị sử dụng mô-đun GPS kết hợp với vi điều khiển và kết nối không dây để giám sát vị trí của vật nuôi, từ đó phát hiện khi vật nuôi đi ra ngoài khu vực được thiết lập và gửi cảnh báo đến người quản lý.

Dự án hướng đến việc ứng dụng công nghệ hiện đại trong nông nghiệp, giúp tăng hiệu quả quản lý, giảm rủi ro thất thoát và nâng cao năng suất chăn nuôi thông minh.

🧠 Chức năng chính
Chức năng	Mô tả
| Chức năng                               | Mô tả                                                                                        |
| --------------------------------------- | -------------------------------------------------------------------------------------------- |
|  Xác định vị trí vật nuôi | Sử dụng mô-đun GPS để thu thập toạ độ thực của vật nuôi (qua thiết bị gắn trên cổ). |
|  Thiết lập vùng an toàn (Geo-fence)                 | Định nghĩa khu vực trang trại bằng toạ độ GPS. Nếu vật nuôi ra ngoài vùng này sẽ bị cảnh báo.                                |
|  Gửi cảnh báo ra ngoài        | Khi vật nuôi vượt ranh giới, hệ thống gửi email hoặc thông báo đến người quản lý.            |
|  Hoạt động độc lập bằng pin           | Thiết bị sử dụng pin sạc hoặc nguồn ngoài, đảm bảo gọn nhẹ và di động.                       |
🔧 Sơ đồ hoạt động hệ thống

  ![sodo](https://github.com/user-attachments/assets/9e9a014f-bec8-4aaa-9b05-b9c2780fd55e)

⚙️ Công nghệ sử dụng
Thành phần	Mô tả
Mô-đun GPS (Neo-6M)	Thu thập vị trí chính xác của vật nuôi (theo thời gian thực).

- Vi điều khiển (ESP32)	Bộ điều khiển trung tâm, xử lý dữ liệu GPS và gửi cảnh báo qua Wi-Fi.

- Kết nối Internet	Sử dụng Wi-Fi hoặc GSM (tùy phiên bản) để gửi cảnh báo.

- Pin Lithium-ion 18650	Cung cấp năng lượng cho toàn bộ thiết bị.

- Vỏ bảo vệ	Chống nước, chống bụi, giúp thiết bị hoạt động ổn định ngoài trời.

🔄 Chu trình hoạt động cơ bản
Khởi động hệ thống:
ESP32 và mô-đun GPS được khởi tạo, kiểm tra kết nối.

Thu thập vị trí liên tục:
GPS cập nhật toạ độ mỗi vài giây (ví dụ: 5 giây/lần).

So sánh vị trí với vùng an toàn:
Nếu toạ độ nằm ngoài ranh giới được thiết lập → hệ thống xử lý cảnh báo.

Gửi cảnh báo:
Gửi email hoặc thông báo đến điện thoại người quản lý.

Tiếp tục lặp lại:
Hệ thống hoạt động liên tục, tiết kiệm năng lượng khi không có sự kiện.

💡 Mục tiêu mở rộng trong tương lai
Kết nối với điện thoại qua Bluetooth để kiểm tra vị trí cục bộ.

Gắn cảm biến đo nhịp tim, nhiệt độ cơ thể vật nuôi để theo dõi sức khỏe.

Tích hợp bản đồ hiển thị trực quan vị trí vật nuôi trên ứng dụng.

Tự động đưa ra cảnh báo nếu vật nuôi không di chuyển trong thời gian dài (có thể bị ốm hoặc bị kẹt).

👨‍💻 Tác giả Họ tên: Lò Văn Bảo
