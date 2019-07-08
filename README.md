Đây là đồ án thầy Lưu Nguyễn Kỳ Thư giao cho mình để làm bài báo cáo cuối kỳ môn Cấu trúc dữ liệu và giải thuật.
1.	Thư viện: Ta tổ chức các danh sách sau: 
- Đầu sách : danh sách tuyến tính là 1 mảng con trỏ (ISBN (C6), Tên sách, Số trang, Tác giả, năm xuất bản, thể loại, con trỏ danh muc sach): con trỏ sẽ trỏ đến các sách thuộc đầu sách tương ứng. (Đầu sách chứa con trỏ trỏ đến danh mục sách.)(DauSach->DanhMucSach)
- Danh mục sách : danh sách liên kết đơn( Mã sách,  trạng thái, vị trí   ). Mỗi cuốn sách chỉ có 1 mã duy nhất; trạng thái của sách bao gồm: 0: cho mượn được, 1: đã có độc giả mượn, 2: sách đã thanh lý . 
- Danh sách thẻ độc giả: cây nhị phân tìm kiếm (MATHE (số nguyên ngẫu nhiên tự động), Ho, Ten,  Phai, trạng thái của thẻ, con trỏ): con trỏ sẽ trỏ đến danh sách các cuốn sách đã và đang mượn.(MaThe->MuonTra)
- Danh sách MUONTRA : danh sách liên kết kép ( MASACH,  NgayMuon, NgayTra, trạng thái): trạng thái =0 là sách đang mượn (chưa trả), =1 là đã trả, =2 : làm mất sách 
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
Chương trình có các chức năng sau: 
1.	Nhập thẻ độc giả: THÊM / XÓA / HIỆU CHỈNH thông tin thẻ độc giả. Mã thẻ độc giả được chương trình tự động lấy ngẫu nhiên và không trùng với các mã thẻ độc giả cũ; Phái chỉ nhận ‘Nam’ hoặc ‘Nữ’; trạng thái thẻ = 0 khi thẻ bị khóa, trạng thái thẻ = 1 khi thẻ  đang hoạt động (được quyền mượn sách). (switch case (menu() tra ve them, xoa ,sua))
2.	In danh sách độc giả : in ra màn hình THEO THỨ TỰ TÊN+HỌ TĂNG DẦN hoặc THEO THỨ TỰ MÃ ĐỘC GIẢ TĂNG DẦN theo yêu cầu của thủ thư. (switch case (menu() tra ve ten+ho tang dan,ma doc gia tang dan))
3.	Nhập thông tin ĐẦU SÁCH và ĐÁNH MÃ sách TỰ ĐỘNG
4.	In danh sách các đầu sách trong thư viện theo từng thể loại>>trong từng thể loại thì in theo thứ tự tên sách tăng dần.(menu chinh->menu theothe loai->menu theo ten(*tat ca deu sap xep tang dan))
5.	Tìm thông tin sách dựa vào tên sách : in ra các thông tin
6.	{mã ISBN, tên sách, tác giả, năm xuất bản, thể loại, các mã sách , trạng thái mã sách trong thư viện.}
7.	Mượn sách : nhập vào mã thẻ độc giả, chương trình sẽ liệt kê các sách mà độc giả đang mượn. Mỗi độc giả chỉ được mượn tối đa 3 cuốn, không cho mượn khi giữ 1 sách quá hạn (7 ngày)
8.	Trả sách 
9.	Liệt kê danh sách các sách mà 1 độc giả đang mượn
10.	In danh sách độc giả mượn sách quá hạn theo thứ tự thời gian quá hạn giảm dần . Kết xuất :
mathe--ho--tên--masach---ten sách---ngày mượn----số ngày quá hạn
11. In 10 đầu sách có số lượt mượn nhiều nhất.
