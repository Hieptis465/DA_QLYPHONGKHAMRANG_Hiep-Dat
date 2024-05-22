#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const char* RED_TEXT ="\033[1;31m";      // mã màu 
const char* ORANGE_TEXT ="\033[0;33m";   
const char* YELLOW_TEXT ="\033[1;33m";   
const char* GREEN_TEXT ="\033[1;32m";    
const char* BLUE_TEXT ="\033[0;34m";     	
const char* INDIGO_TEXT ="\033[1;94m";   
const char* VIOLET_TEXT ="\033[1;35m";   
const char* PINK_TEXT ="\033[1;35m";   
const char* RESET_TEXT ="\033[1;37m";
const char* GRAY_TEXT = "\033[1;30m";      

class benhnhan                    // lop thong tin benh nhan 
{                          
private:
    int id, phikham, phidieutri, phithuoc, tongtien;
    string sdt, tenbn, ngaysinh, quequan, ngaydieutri;
public:
    void input()                     // ham nhap thông tin benh nhan 
	{                       
        cin.ignore();
        cout <<"\nNhap ma benh nhan: ";
        cin >> id;
        fflush(stdin);
        while (id < 0) 
		{                        // neu id < 0 nhap lai id 
            cout <<RED_TEXT<<"\nVui long nhap ma benh nhan > 0: ";     
            cout<< RESET_TEXT;
            cin >> id;
            fflush(stdin);
        }
        cout <<"\nNhap ten benh nhan: ";
        getline(cin, tenbn);
        fflush(stdin);
        cout <<"\nNhap ngay sinh: ";
        getline(cin, ngaysinh);
        fflush(stdin);
        cout <<"\nNhap que quan: ";
        getline(cin, quequan);
        fflush(stdin);
        cout <<"\nNhap so dien thoai: ";
        cin >> sdt;
        fflush(stdin);
		cout <<"\nNgay dieu tri: ";
        getline(cin, ngaydieutri);
        fflush(stdin);
        cout <<"\nPhi kham benh(VND): ";
        cin >> phikham;
        fflush(stdin);
        cout <<"\nPhi dieu tri(VND): ";
        cin >> phidieutri;
        fflush(stdin);
        cout <<"\nPhi thuoc(VND): ";
        cin >> phithuoc;
        fflush(stdin);
        tongtien = (phikham + phidieutri + phithuoc);            // tinh tong chi phi benh nhan 
        cout <<RED_TEXT<<"\nTong tien(VND) : " << tongtien<<endl; 
        cout<<RESET_TEXT; 
        fflush(stdin);
    }
    void output()                        // ham xuat thông tin benh nhan 
	{                       
        cout << setw(8) <<left<< id << setw(20) << tenbn << setw(13) << ngaysinh<< setw(15) << quequan << setw(12) << sdt << setw(12) << ngaydieutri << setw(11) << phikham << setw(11) << phidieutri << setw(11) << phithuoc << setw(11) << tongtien<<endl;
    }
    void docfilebn(ifstream& is) {
        is >> id >> tenbn >> ngaysinh >> quequan >> sdt >> ngaydieutri >> phikham >> phidieutri >> phithuoc >> tongtien;
    }
    int get_id() {                       //public cac thông tin benh nhan de use cho class qlyphongkham 
        return id;
    }
    string get_tenbn() {
    	return tenbn; 
	}
	string get_ngaysinh(){
		return ngaysinh;
	}
	string get_quequan() {
		return quequan;
	}
	string get_sdt(){
		return sdt;
	}
	int get_tongtien() {
        return tongtien;
    }
    string get_ngaydieutri(){
    	return ngaydieutri;
	}
	int get_phikham() {
		return phikham;
	}
	int get_phidieutri(){
		return phidieutri;
	}
	int get_phithuoc(){
		return phithuoc;
	}
};
class NhanSu                  // lop thong tin nhan su 
{                     
private:
    string SDT, Ten, date, que;
    int ID, ngaycong, phucap, luong ; 
    static int hesoluongcoban;
public:
    string vitri;
    void INPUT()                   // ham nhap thong tin nhân su 
	{                 
        cin.ignore();
        cout <<"\nNhap ma so nhan su: ";
        cin >> ID;
        fflush(stdin);
        while (ID < 0) 
		{                      // neu id <0 yeu cau nhap lai 
            cout <<RED_TEXT<<"\nVui long nhap ma nhan su > 0: ";
            cout <<RESET_TEXT; 
            cin >> ID;
            fflush(stdin);
        }
        cout <<"\nNhap ten nhan su: ";
        getline(cin, Ten);
        fflush(stdin);
        cout <<"\nNhap ngay sinh: ";
        getline(cin, date);
        fflush(stdin);
        cout <<"\nNhap que quan: ";
        getline(cin, que);
        fflush(stdin);
        cout <<"\nNhap so dien thoai: ";
        cin >> SDT;
        fflush(stdin);
        cout <<"\nNhap vi tri lam viec( y ta or bac si or quan ly): ";
        getline(cin, vitri);
        fflush(stdin);
		cout<<"\nNhap so ngay cong: ";
		cin>>ngaycong;
		fflush(stdin); 
        if (vitri == "y ta") {                 // gán giá tri phu cap cho tung vi tri làm viec 
            phucap = 1000000;
        } else if (vitri == "bac si") {
            phucap = 3000000;
        } else if (vitri == "quan ly") {
            phucap = 5000000;
        } else {
            phucap = 0;
        }
        luong = static_cast<int>(ngaycong) * hesoluongcoban + phucap;               //tinh luong theo he so luong co ban va ngay cong + phu cap 
        cout<<RED_TEXT<<"\nTong tien luong(VND) la: "<<luong; 
    }   
    
    void OUTPUT()                   // ham xuat thong tin nhan su 
	{                         
        cout <<setw(8)<< ID<< setw(20) << Ten << setw(13) << date<<setw(15)<<que<<setw(12)<<SDT<<setw(10)<<vitri<<setw(10)<<ngaycong<<setw(11)<<phucap<<setw(13)<<luong<<endl; 
    }
    int get_ID() {
        return ID;
	}
	int get_luong() {
        return luong;
	}
	string get_Ten(){
		return Ten; 
	}
	string get_date(){
		return date; 
	}
	string get_que(){
		return que; 
	}
	string get_SDT(){
		return SDT; 
	}
	int get_ngaycong(){
		return ngaycong; 
	} 
	string get_vitri(){
		return vitri; 
	}
	int get_phucap(){
		return phucap; 
	} 
};
int NhanSu::hesoluongcoban = 550000;     // khoi tao bien tinh he so luong co ban = 550000 
class qlythietbi                       // class qly thiet bi phong kham rang 
{
private:
    int matb, soluong;        
    string tenthietbi, tinhtrang, ngaysx, ngaymua, ngaybaoduong;   
public:
    void Input() 
	{
        cin.ignore();
        cout <<"\nNhap ma so TB: ";
        cin >> matb;
        fflush(stdin);
        while (matb < 0)
		{
            cout <<RED_TEXT<<"\nVui long nhap ma TB > 0: ";
            cout <<RESET_TEXT; 
            cin >> matb;
		}
            fflush(stdin);
            cout << "\nNhap so luong: ";
            cin >> soluong;
            fflush(stdin);
            cout << "\nNhap ten thiet bi: ";
            getline(cin,tenthietbi);
            fflush(stdin);
            cout << "\nNhap tinh trang thiet bi (new or old): ";
            getline(cin,tinhtrang);
            fflush(stdin);
            cout << "\nNhap ngay san xuat cua thiet bi: ";
            getline(cin,ngaysx);
            fflush(stdin);
            cout << "\nNhap ngay mua thiet bi: ";
            getline(cin,ngaymua);
            fflush(stdin);
            cout << "\nNhap ghi chu ngay bao duong thiet bi: ";
            getline(cin,ngaybaoduong);
            cout<<RESET_TEXT<<endl; 
        }
    void Output() 
	{
		cout<<setw(10)<<left<<matb<<setw(8)<<left<<soluong<<setw(20)<<left<<tenthietbi<<setw(13)<<left<<tinhtrang<<setw(14)<<left<<ngaysx<<setw(14)<<left<<ngaymua<<setw(14)<<left<<ngaybaoduong<<endl; 
	}   
	int get_matb(){
		return matb; 
	} 
	int get_soluong(){
		return soluong;
	}
	string get_tenthietbi(){
		return tenthietbi;
	}
	string get_ngaysx(){
		return ngaysx;
	}
	string get_ngaymua(){
		return ngaymua;
	}
	string get_ngaybaoduong(){
		return ngaybaoduong;
	}
	string get_tinhtrang(){
		return tinhtrang; 
	}				
};
class quanlyphongkham : public benhnhan, qlythietbi, NhanSu
{                     // lop QLY PHONG KHAM RANG ke thua lop BENH NHAN, NHAN SU, QLY THIET BI
public:
    benhnhan bn;
    NhanSu ns;
    qlythietbi tb;                                                             
	// goi cac PHUONG THUC nhap xuat thong tin benh nhan , nhan su, chi phi 
    void nhap() { 
        bn.input();
    }
    void xuat() {
        bn.output();
    }
    void Nhap() {
        ns.INPUT();
    }
    void Xuat() {
        ns.OUTPUT();
    }
    void NHAP() {
        tb.Input();
    }
    void XUAT() {
        tb.Output();
    }
};
void nhapds(quanlyphongkham a[], int n) 
{                         // ham nhap danh sach BENH NHAN
    benhnhan bn;
    for (int i = 0; i < n; i++) 
	{
    	int res = 0;
        do 
		{
            res = 0;
            cout<<endl; 
            cout <<YELLOW_TEXT<<"\nBenh nhan thu: " << i + 1 << ""<<endl; 
            cout<< GREEN_TEXT<<"======================" <<endl; 
            cout<<RESET_TEXT; 
            a[i].nhap();
            for (int j = 0; j < i; j++) 
			{
                if (a[j].bn.get_id() == a[i].bn.get_id()) 
				{            // khi id vua nhap bang id vua nhap truoc do thì nhap lai 
                    cout <<RED_TEXT<<"\n***Ma benh nhan khong duoc trung nhau, Moi nhap lai!" << endl;
                    cout<<RESET_TEXT; 
                    res++;
                }
            }
        } while (res != 0);                                           // neu nhap trùng id nhap lai  
    }
}
void xuatds(quanlyphongkham a[], int n) 
{                             // ham xuat danh sach BENH NHAN  
	cout<<endl; 
    cout <<YELLOW_TEXT<< setw(8) << left << "MaBN" << setw(20) << left << "TenBN" << setw(13) << left << "NgaySinh" << setw(15) << left << "QueQuan" << setw(12) << left << "SDT" << setw(12) << left << "Ngaydieutri" << setw(11) << left << "Phikham" << setw(11) << left << "Phidieutri" << setw(11) << left << "Phithuoc" << setw(11) << left << "Tongtien" << endl;
    cout<<RESET_TEXT; 
    for (int i = 0; i < n; i++) 
	{
        a[i].xuat();
    }
}
void xuatfile(quanlyphongkham a[], int n) 
{                           // ham ghi thong tin BENH NHAN vao file danhsach.txt 
    ofstream ofs("C:\\Users\\acer\\OneDrive\\Documents\\file\\danhsach.txt");
    if (ofs.is_open()) 
	{
        ofs << setw(10) << left << "MaBN" << setw(20) << left << "TenBN" << setw(15) << left << "NgaySinh" << setw(15) << left << "QueQuan" << setw(14) << left << "SDT" << setw(14) << left << "Ngaydieutri" << setw(13) << left << "Phikham" << setw(13) << left << "Phidieutri" << setw(13) << left << "Phithuoc" << setw(13) << left << "Tongtien" << endl;
        for (int i = 0; i < n; i++) 
		{
            ofs << setw(10) << left << a[i].bn.get_id() ;
            ofs << setw(20) << left << a[i].bn.get_tenbn();
            ofs << setw(15) << left << a[i].bn.get_ngaysinh();
            ofs << setw(15) << left << a[i].bn.get_quequan();
            ofs << setw(14) << left << a[i].bn.get_sdt();
            ofs << setw(14) << left << a[i].bn.get_ngaydieutri();
            ofs << setw(13) << left << a[i].bn.get_phikham();
            ofs << setw(13) << left << a[i].bn.get_phidieutri();
            ofs << setw(13) << left << a[i].bn.get_phithuoc();
            ofs << setw(13) << left << a[i].bn.get_tongtien()<< endl;          
    }
        ofs.close();
        cout << GREEN_TEXT << "\nXuat file thanh cong!" << RESET_TEXT << endl;
    } else 
	{
        cout << RED_TEXT <<"\nKhong the mo file de ghi!" << RESET_TEXT << endl;
    }
}
void DocfileBN (quanlyphongkham a[], int n)                        // ham doc thong tin benh nhan tu file danhsachbenhnhan.txt roi xuat ra man hinh 
{                 
    ifstream ifs("C:\\Users\\acer\\OneDrive\\Documents\\file\\danhsachbenhnhan.txt");
    if (!ifs) 
	{
        cout << "Mo file that bai." << endl;
        return;
    }
    cout << YELLOW_TEXT << setw(8) << left << "MaBN"<< setw(20) << left << "TenBN"<< setw(13) << left << "NgaySinh"<< setw(15) << left << "QueQuan"<< setw(12) << left << "SDT"<< setw(12) << left << "Ngaydieutri"<< setw(11) << left << "Phikham"<< setw(11) << left << "Phidieutri"<< setw(11) << left << "Phithuoc"<< setw(11) << left << "Tongtien" << endl;
    cout<<RESET_TEXT<<endl; 
    for (int i = 0; i < n; ++i) 
	{
        a[i].docfilebn(ifs);
        if (ifs) 
		{
            cout << setw(8) << left << a[i].get_id()<< setw(20) << left << a[i].get_tenbn()<< setw(13) << left << a[i].get_ngaysinh()<< setw(15) << left << a[i].get_quequan()<< setw(12) << left << a[i].get_sdt()<< setw(12) << left << a[i].get_ngaydieutri()<< setw(11) << left << a[i].get_phikham() << setw(11) << left << a[i].get_phidieutri()<< setw(11) << left << a[i].get_phithuoc()<< setw(11) << left << a[i].get_tongtien() << endl;
        } else 
		{
            break;               // neu khong con du lieu de doc file thi thoat khoi vong lap 
        }
    }
    ifs.close();
}
void TONG_TIEN(quanlyphongkham a[], int N)             // ham tinh tong tien cua tat ca BENH NHAN
{
	benhnhan bn;
    int tong_tien = 0;
    for (int i = 0; i < N; ++i) 
	{
        tong_tien += a[i].bn.get_tongtien();
    }
		cout <<RED_TEXT<< "\nTong tien benh nhan chi tra la: " << tong_tien <<RESET_TEXT<<endl; 
}
void timkiem(quanlyphongkham a[], int n) 
{                   // ham tim kiem thong tin BENH NHAN bang id 
    int x;                                                  //  khai bao ma benh nhan can tim  
    benhnhan bn;
    int count = 0;                                        // bien dem kiem tra xem có ma benh nhan can tim khong 
    cout <<YELLOW_TEXT<<"\nNhap ma benh nhan can tim: ";
    cin >> x;
    cout<< GREEN_TEXT<<"============================" <<endl; 
    cout<<RESET_TEXT;
    cout<<endl; 
    cout << setw(8) << left << "MaBN" << setw(20) << left << "TenBN" << setw(13) << left << "NgaySinh" << setw(15) << left << "QueQuan" << setw(12) << left << "SDT" << setw(12) << left << "Ngaydieutri"
         << setw(11) << left << "Phikham" << setw(11) << left << "Phidieutri" << setw(11) << left << "Phithuoc" << setw(1) << left << "Tongtien" << endl;
    for (int i = 0; i < n; i++)
	{
        if (a[i].bn.get_id() == x) 
		{                   // neu x = id benh nhan da luu ==> Xuat bang thong tin benh nhan  
            a[i].xuat();                              // tang bien dem 
            count++;
        }
    }
    if (count == 0) 
	{                             // Neu khong tim thay ma benh nhan....
        cout <<RED_TEXT<<"\nKhong tim thay du lieu ban nhap";
        cout<<RESET_TEXT; 
    }
}
void thembn(quanlyphongkham a[], int& n) 
{                   // ham them thong tin BENH NHAN 
    n++;                 // tang so luong benh nhan lên 1 
    int res = 0;           // Khai báo bien kiem tra có bi trùng id k 
    benhnhan bn;
    do 
	{
        res = 0;            
        cout <<YELLOW_TEXT<<"\nNhap thong tin benh nhan can them: "<<endl; 
        cout<< GREEN_TEXT<<"=============================" <<endl; 
        cout<<RESET_TEXT;
        a[n-1].nhap();
        for (int i = 0; i < n - 1; i++) 
		{
        if (a[i].bn.get_id() == a[n - 1].bn.get_id()) 
			{
                cout <<RED_TEXT<<"\nMa benh nhan khong duoc trung nhau. Moi ban nhap lai!" << endl;
                cout<<RESET_TEXT; 
                res++;
            }
        }
    } while (res != 0);
}
void xoabn(quanlyphongkham a[], int& n) 
{              // ham xoa BENH NHAN bang id 
    int xoa;          // khai bao bien ma bn can xoa 
    int res = 0;         // khai bao bien kiem tra ma benh nhan 
    benhnhan bn;
    cout <<YELLOW_TEXT<<"\nNhap ma benh nhan can xoa: ";
    cin >> xoa;
    cout<<endl; 
    cout<< GREEN_TEXT<<"===========================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < n; i++) 
	{
        if (a[i].bn.get_id() == xoa) 
	    {
           res++;          // tang res danh dau da tim thay ma bn can xoa  
           for (int j = i; j < n - 1; j++) 
		    {        // Vong lap dich chuyen cac ma benh nhan sau benh nhan can xoa lên vi tri truoc 
              a[j] = a[j + 1];
            }
        }
    }
    if (res == 0) 
	{            // khong tim thay ma benh nhan 
        cout << RED_TEXT <<"\nMa so benh nhan khong ton tai!";
    } else {
        n--;                   // giam so luong mang chua benh nhan lui 1 
        cout <<GREEN_TEXT<<"\nDa xoa benh nhan co ma so " << xoa << " thanh cong!"<<endl;
        cout<<RESET_TEXT; 
    }
}
void suatt(quanlyphongkham a[], int n) 
{               //ham sua thong tin BENH NHAN  
    int sua;
    int count = 0;
    benhnhan bn;
    cout <<YELLOW_TEXT<<"\nNhap ma benh nhan can sua: ";
    cout<<RESET_TEXT; 
    cin >> sua;
    cout<< GREEN_TEXT<<"\n======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < n; i++) 
	{
        if (a[i].bn.get_id() == sua) 
		{
            a[i].nhap();
            cout<<GREEN_TEXT<<"\nSua thong tin benh nhan thanh cong !\n";
            cout<<RESET_TEXT; 
            count++;
        }
    }
    if (count == 0) 
	{
        cout <<RED_TEXT<<"Khong tim thay du lieu !";
        cout<<RESET_TEXT; 
    }
}
void nhapdsns(quanlyphongkham a[], int N) 
{                      // ham nhap thong tin NHAN SU 
    int res = 0;
    NhanSu ns;
    for (int i = 0; i < N; i++) 
	{
    	do 
		{ 
    	res=0; 
        cout <<YELLOW_TEXT<<"\nNhan su thu: " << i + 1 << ""<<endl; 
        cout<< GREEN_TEXT<<"======================" <<endl; 
        cout<<RESET_TEXT;
        a[i].Nhap();
        for (int j = 0; j < i; j++) 
		    {
                if (a[j].ns.get_ID() == a[i].ns.get_ID()) 
				{
                    cout <<RED_TEXT<<"\n***Ma nhan su khong duoc trung nhau, Moi nhap lai!" << endl;
                    cout<<RESET_TEXT;
                    res++;
                }
            }
        } while (res != 0);
    }
}
void xuatdsns(quanlyphongkham a[], int N) 
{                   // ham xuat thong tin NHAN SU 
    cout <<YELLOW_TEXT<<setw(8)<<left<<"MaNS"<<setw(20)<<left<< "Ten nhan su" <<setw(13)<<left<<"Ngay sinh"<<setw(15)<< left << "Que quan" << setw(12) << left << "SDT" << setw(10) << left << "Vi tri" <<setw(10)<< left <<"Ngay Cong"<<setw(11)<<left<<"Phu Cap"<<setw(13)<<left<<"Luong"<<endl; 
    cout<< RESET_TEXT; 
    for (int i = 0; i < N; i++) 
	{
        a[i].Xuat();      
    }
}
void tongluong(quanlyphongkham a[], int N)               // ham tinh tong luong phai chi tra cho NHAN SU
{
	NhanSu ns;
    int tongluong = 0;
    for (int i = 0; i < N; ++i) 
	{
        tongluong += a[i].ns.get_luong();
    }
		cout <<RED_TEXT<< "\nTong tien luong phai tra cho tat ca nhan su: " << tongluong <<RESET_TEXT<<endl; 
}
void timkiemnhansu(quanlyphongkham a[], int N) 
{                   // ham tim kiem thong tin NHAN SU bang ID 
    int X;
    NhanSu ns;
    int count = 0;
    cout <<YELLOW_TEXT<<"\nNhap ma nhan su can tim: ";
    cin >> X;
    cout<< GREEN_TEXT<<"=============================" <<endl; 
    cout<<RESET_TEXT;
    cout<<endl; 
    cout <<YELLOW_TEXT<<setw(8)<<left<<"MaNS"<<setw(20)<<left<< "Ten nhan su" <<setw(13)<<left<<"Ngay sinh"<<setw(15)<< left << "Que quan" << setw(12) << left << "SDT" << setw(10) << left << "Vi tri" <<setw(10)<< left <<"Ngay Cong"<<setw(11)<<left<<"Phu Cap"<<setw(13)<<left<<"Luong"<<endl; 
    cout << RESET_TEXT;
	for (int i = 0; i < N; i++) 
	{
        if (a[i].ns.get_ID() == X) 
		{
            a[i].Xuat();
            count++;
        }
    }
    if (count == 0) 
	{
        cout <<RED_TEXT<<"\nKhong tim thay du lieu ban nhap";
        cout<<RESET_TEXT; 
    }
}
void themns(quanlyphongkham a[], int& N) 
{                   // ham them thong tin NHAN SU
    N++;
    int res = 0;
    NhanSu ns;
    do 
	{
        res = 0;
        cout <<YELLOW_TEXT<<"\nNhap thong tin nhan su can them: "<<endl; 
        cout<< GREEN_TEXT<<"======================" <<endl; 
        cout<<RESET_TEXT;
        a[N - 1].Nhap();
        for (int i = 0; i < N - 1; i++) 
		{
        if (a[i].ns.get_ID() == a[N - 1].ns.get_ID()) 
			{
                cout <<RED_TEXT<<"\nMa nhan su khong duoc trung nhau. Moi nhap lai!" << endl;
                cout<<RESET_TEXT; 
                res++;
            }
        }
    } while (res != 0);
}
void xoans(quanlyphongkham a[], int& N) 
{              // ham xoa NHAN SU bang ID 
    int xoa;
    int res = 0;
    NhanSu ns;
    cout <<YELLOW_TEXT<<"\nNhap ma nhan su can xoa: ";
    cin >> xoa;
    cout<<endl; 
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < N; i++) 
	{
    if (a[i].ns.get_ID() == xoa) 
	{
        res++;
        for (int j = i; j < N - 1; j++)
		    {
              a[j] = a[j + 1];
            }
        }
    }
    if (res == 0) 
	{
        cout << RED_TEXT <<"\nMa so nhan su khong ton tai!";
    } else 
	{
        N--;
        cout <<GREEN_TEXT<<"\nDa xoa nhan su co ma so " << xoa <<" thanh cong!";
        cout<<RESET_TEXT; 
    }
}
void suattns(quanlyphongkham a[], int N) 
{               //ham sua thong tin NHAN SU  
    int sua;
    int count = 0;
    NhanSu ns;
    cout <<YELLOW_TEXT<<"\nNhap ma nhan su can sua: ";
    cout<<RESET_TEXT; 
    cin >> sua;
    cout<< GREEN_TEXT<<"\n======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < N; i++) 
	{
        if (a[i].ns.get_ID() == sua) 
		{
            a[i].Nhap();
            cout<<GREEN_TEXT<<"\nSua thong tin nhan su thanh cong !";
            cout<<RESET_TEXT; 
            count++;
        }
    }
    if (count == 0) 
	{
        cout <<RED_TEXT<<"Khong tim thay du lieu !";
        cout<<RESET_TEXT; 
    }
}
void xuatfilenhansu(quanlyphongkham a[], int N) 
{              // ham ghi thong tin NHAN SU vao file danhsachnhansu.txt 
    ofstream ofs("C:\\Users\\acer\\OneDrive\\Documents\\file\\danhsachnhansu.txt");
    if (ofs.is_open()) 
	{
        ofs <<setw(8)<<left<<"MaNS"<<setw(20)<<left<< "Ten nhan su" <<setw(13)<<left<<"Ngay sinh"<<setw(15)<< left << "Que quan" << setw(12) << left << "SDT" << setw(10) << left << "Vi tri" <<setw(12)<< left <<"Ngay Cong"<<setw(11)<<left<<"Phu Cap"<<setw(13)<<left<<"luong"<<endl; 
        for (int i = 0; i < N; i++) 
		{
            ofs << setw(8) << left << a[i].ns.get_ID() ;
            ofs << setw(20) << left << a[i].ns.get_Ten();
            ofs << setw(13) << left << a[i].ns.get_date();
            ofs << setw(15) << left << a[i].ns.get_que();
            ofs << setw(12) << left << a[i].ns.get_SDT();
            ofs << setw(10) << left << a[i].ns.get_vitri();
            ofs << setw(12) << left << a[i].ns.get_ngaycong();
            ofs << setw(11) << left << a[i].ns.get_phucap();
            ofs << setw(13) << left << a[i].ns.get_luong();
			ofs<<endl;     
    }
        ofs.close();
        cout << GREEN_TEXT <<"\nXuat file thanh cong!" << RESET_TEXT << endl;
    } else 
	{
        cout << RED_TEXT <<"\nKhong the mo file de ghi!" << RESET_TEXT << endl;
    }
}
void nhaptb(quanlyphongkham a[], int nn) 
{                         // ham nhap danh sach THIET BI 
    qlythietbi tb;
    for (int i = 0; i < nn; i++) 
	{
    	int res = 0;
        do 
		{
            res = 0;
            cout<<endl; 
            cout <<YELLOW_TEXT<<"\nThiet bi thu: " << i + 1 << ""<<endl; 
            cout<< GREEN_TEXT<<"======================" <<endl; 
            cout<<RESET_TEXT; 
            a[i].NHAP();
            for (int j = 0; j < i; j++) 
			{
                if (a[j].tb.get_matb() == a[i].tb.get_matb()) 
				{            // khi MA_TB vua nhap bang MA_TB vua nhap truoc do thì nhap lai 
                    cout <<RED_TEXT<<"\n***Ma thiet bi khong duoc trung nhau, Moi nhap lai!" << endl;
                    cout<<RESET_TEXT; 
                    res++;
                }
            }
        } while (res != 0);                                           // neu nhap trùng MA_TB nhap lai  
    }
}
void xuattb(quanlyphongkham a[], int nn) 
{                   // ham xuat thong tin THIET BI
    cout<<YELLOW_TEXT<<setw(10)<<left<<"MaTB"<<setw(8)<<left<<"SoLuong"<<setw(20)<<left<<"TenTB"<<setw(13)<<left<<"TinhTrang"<<setw(14)<<left<<"NgaySanXuat"<<setw(14)<<left<<"NgayMua"<<setw(13)<<left<<"NgayBaoDuong"<<endl;
    cout<< RESET_TEXT; 
    for (int i = 0; i < nn; i++) 
	{
        a[i].XUAT();      
    }
}
void xuatfileTB (quanlyphongkham a[], int nn) 
{              // ham ghi thong tin THIET BI vao file danhsachnhansu.txt 
    ofstream ofs("C:\\Users\\acer\\OneDrive\\Documents\\file\\danhsachthietbi.txt");
    if (ofs.is_open()) 
	{
        ofs <<setw(10)<<left<<"MaTB"<<setw(8)<<left<<"SoLuong"<<setw(20)<<left<<"TenTB"<<setw(13)<<left<<"TinhTrang"<<setw(14)<<left<<"NgaySanXuat"<<setw(14)<<left<<"NgayMua"<<setw(13)<<left<<"NgayBaoDuong"<<endl;
        for (int i = 0; i < nn; i++) 
		{
            ofs << setw(10) << left << a[i].tb.get_matb() ;
            ofs << setw(8) << left << a[i].tb.get_soluong();
            ofs << setw(20) << left << a[i].tb.get_tenthietbi();
            ofs << setw(13) << left << a[i].tb.get_tinhtrang();
            ofs << setw(14) << left << a[i].tb.get_ngaysx();
            ofs << setw(14) << left << a[i].tb.get_ngaymua();
            ofs << setw(14) << left << a[i].tb.get_ngaybaoduong();
			ofs<<endl;     
    }
        ofs.close();
        cout << GREEN_TEXT <<"\nXuat file thanh cong!" << RESET_TEXT << endl;
    } else 
	{
        cout << RED_TEXT <<"\nKhong the mo file de ghi!" << RESET_TEXT << endl;
    }
}
void timkiemtb(quanlyphongkham a[], int nn) 
{                   // ham tim kiem thong tin THIET BI bang MA_TB 
    int X;
    qlythietbi tb;
    int count = 0;
    cout <<YELLOW_TEXT<<"\nNhap ma thiet bi can tim: ";
    cin >> X;
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    cout<<endl; 
    cout <<YELLOW_TEXT<<setw(10)<<left<<"MaTB"<<setw(8)<<left<<"SoLuong"<<setw(20)<<left<<"TenTB"<<setw(13)<<left<<"TinhTrang"<<setw(14)<<left<<"NgaySanXuat"<<setw(14)<<left<<"NgayMua"<<setw(13)<<left<<"NgayBaoDuong"<<endl;
    cout << RESET_TEXT;
	for (int i = 0; i < nn; i++) 
	{
        if (a[i].tb.get_matb() == X) 
		{
            a[i].XUAT();
            count++;
        }
    }
    if (count == 0) 
	{
        cout <<RED_TEXT<<"\nKhong tim thay du lieu ban nhap";
        cout<<RESET_TEXT; 
    }
}
void themtb(quanlyphongkham a[], int& nn) 
{                   // ham them thong tin THIET BI
    nn++;
    int res = 0;
    qlythietbi tb;
    do 
	{
        res = 0;
        cout <<YELLOW_TEXT<<"\nNhap thong tin thiet bi can them: "<<endl; 
        cout<< GREEN_TEXT<<"======================" <<endl; 
        cout<<RESET_TEXT;
        a[nn - 1].NHAP();
        for (int i = 0; i < nn - 1; i++) 
		{
        if (a[i].tb.get_matb() == a[nn - 1].tb.get_matb()) 
			{
                cout <<RED_TEXT<<"\nMa thiet bi khong duoc trung nhau. Moi nhap lai!" << endl;
                cout<<RESET_TEXT; 
                res++;
            }
        }
    } while (res != 0);
}
void xoatb(quanlyphongkham a[], int& nn) 
{              // ham xoa THIET BI bang MA_TB 
    int xoa;
    int res = 0;
    qlythietbi tb;
    cout <<YELLOW_TEXT<<"\nNhap ma thiet bi can xoa: ";
    cin >> xoa;
    cout<<endl; 
    cout<< GREEN_TEXT<<"======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i < nn; i++) 
	{
    if (a[i].tb.get_matb() == xoa) 
	{
        res++;
        for (int j = i; j < nn - 1; j++)
		    {
              a[j] = a[j + 1];
            }
        }
    }
    if (res == 0) 
	{
        cout << RED_TEXT <<"\nMa so thiet bi khong ton tai!";
    } else 
	{
        nn--;
        cout <<GREEN_TEXT<<"\nDa xoa thiet bi co ma so " << xoa <<" thanh cong!";
        cout<<RESET_TEXT; 
    }
}
void suatttb(quanlyphongkham a[], int nn) 
{               //ham sua thong tin THIET BI
    int sua;
    int count = 0;
    qlythietbi tb;
    cout <<YELLOW_TEXT<<"\nNhap ma thiet bi can sua: ";
    cout<<RESET_TEXT; 
    cin >> sua;
    cout<< GREEN_TEXT<<"\n======================" <<endl; 
    cout<<RESET_TEXT;
    for (int i = 0; i <nn; i++) 
	{
        if (a[i].tb.get_matb() == sua) 
		{
            a[i].NHAP();
            cout<<GREEN_TEXT<<"\nSua thong tin thiet bi thanh cong !";
            cout<<RESET_TEXT; 
            count++;
        }
    }
    if (count == 0) 
	{
        cout <<RED_TEXT<<"Khong tim thay du lieu !";
        cout<<RESET_TEXT; 
    }
}
void menu(quanlyphongkham a[], int n, int N, int nn) 
{                   // ham menu tong 
    int LUACHON;
    qlythietbi tb;
    do 
	{
        system("cls");
        cout << RESET_TEXT << "\t                                                        Quan Ly Phong Kham Rang " << RED_TEXT << "H" << ORANGE_TEXT << "I" << YELLOW_TEXT << "E" << GREEN_TEXT << "P" << BLUE_TEXT << "D" << INDIGO_TEXT << "A" << VIOLET_TEXT << "T \t" << endl;
        cout << GREEN_TEXT << "\n                                                           ==========================================" << endl;
        cout << GREEN_TEXT << "                                                           =                                        =" << endl;
        cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "           1. Quan ly benh nhan        " << GREEN_TEXT << " =" << endl;
        cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "           2. Quan ly nhan su          " << GREEN_TEXT << " =" << endl;
        cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "           3. Quan ly thiet bi         " << GREEN_TEXT << " =" << endl;
        cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "           4. Exit                     " << GREEN_TEXT << " =" << endl;
        cout << GREEN_TEXT << "                                                           =                                        =" << endl;
        cout << GREEN_TEXT << "                                                           ==========================================" << endl;
        cout << YELLOW_TEXT << "\t                                                   ====> Nhap lua chon cua ban: ";
        cout << RESET_TEXT;
        cin >> LUACHON;

        switch (LUACHON) 
		{
            case 1:
                int luachonbn;
                do 
				{
                    system("cls");
                    cout << RESET_TEXT << "\t                                                         Quan Ly Benh Nhan Phong Kham Rang " << RED_TEXT << "H" << ORANGE_TEXT << "I" << YELLOW_TEXT << "E" << GREEN_TEXT << "P" << BLUE_TEXT << "D" << INDIGO_TEXT << "A" << VIOLET_TEXT << "T  \t" << endl;
                    cout << GREEN_TEXT << "\n                                                           ====================================================" << endl;
                    cout << GREEN_TEXT << "                                                           =                                                  =" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            1. Nhap danh sach benh nhan           " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            2. Xuat danh sach benh nhan           " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            3. Xuat file danh sach                " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            4. Doc file va xuat                   " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            5. Tong tien BN da chi tra            " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            6. Tim kiem benh nhan                 " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            7. Sua thong tin benh nhan            " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            8. Xoa benh nhan                      " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            9. Them benh nhan                     " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            10. Tro ve menu chinh                  " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =                                                  =" << endl;
                    cout << GREEN_TEXT << "                                                           ====================================================" << endl;
                    cout << YELLOW_TEXT << "\t                                                   ====> Nhap lua chon cua ban: ";
                    cout << RESET_TEXT;
                    cin >> luachonbn;

                    switch (luachonbn) 
					{
                        case 1:
                            nhapds(a, n);
                            system("pause");
                            break;
                        case 2:
                            xuatds(a, n);
                            system("pause");
                            break;
                        case 3:
                            xuatfile(a, n);
                            system("pause");
                            break;
                        case 5:
                            TONG_TIEN(a, n);
                            system("pause");
                            break;
                        case 6:
                            timkiem(a, n);
                            system("pause");
                            break;
                        case 9:
                            thembn(a, n);
                            system("pause");
                            break;
                        case 4:
                            DocfileBN(a,n); 
                            system("pause");
                            break;
                        case 8:
                            xoabn(a, n);
                            system("pause");
                            break;
                        case 7:
                            suatt(a, n);
                            system("pause");
                            break;
                        case 10:
                            break;
                        default:
                            cout << RED_TEXT << "Khong co du lieu ban nhap!";
                            cout << RESET_TEXT;
                            system("pause");
                            break;
                    }
                } while (luachonbn != 10);
                break;
            case 2:
                int luachonns;
                do 
				{
                    system("cls");
                    cout << RESET_TEXT << "\t                                                        Quan Ly Nhan Su Phong Kham Rang " << RED_TEXT << "H" << ORANGE_TEXT << "I" << YELLOW_TEXT << "E" << GREEN_TEXT << "P" << BLUE_TEXT << "D" << INDIGO_TEXT << "A" << VIOLET_TEXT << "T \t" << endl;
                    cout << GREEN_TEXT << "\n                                                           =================================================" << endl;
                    cout << GREEN_TEXT << "                                                           =                                               =" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            1. Nhap danh sach nhan su          " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            2. Xuat danh sach nhan su          " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            3. Xuat file danh sach             " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            4. Tong tien luong phai tra        " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            5. Tim kiem nhan su                " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            6. Sua thong tin nhan su           " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            7. Xoa nhan su                     " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            8. Them nhan su                    " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            9. Tro ve menu chinh               " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =                                               =" << endl;
                    cout << GREEN_TEXT << "                                                           =================================================" << endl;
                    cout << YELLOW_TEXT << "\t                                                   ====> Nhap lua chon cua ban: ";
                    cout << RESET_TEXT;
                    cin >> luachonns;

                    switch (luachonns) 
					{
                        case 1:
                            nhapdsns(a, N);
                            system("pause");
                            break;
                        case 2:
                            xuatdsns(a, N);
                            system("pause");
                            break;
                        case 4:
                            timkiemnhansu(a, N);
                            system("pause");
                            break;
                        case 8:
                            themns(a, N);
                            system("pause");
                            break;
                        case 7:
                            xoans(a, N);
                            system("pause");
                            break;
                        case 6:
                            suattns(a, N);
                            system("pause");
                            break;
                        case 5:
                            tongluong(a, N);
                            system("pause");
                            break;
                        case 3:
                            xuatfilenhansu(a, N);
                            system("pause");
                            break;
                        case 9:
                            break;
                        default:
                            cout << RED_TEXT << "Khong co du lieu ban nhap!";
                            cout << RESET_TEXT;
                            system("pause");
                            break;
                    }
                } while (luachonns != 9);
                break;
            case 3:            // ham menu lua chon 
                int luachontb;
                do 
				{
                    system("cls"); 
                    cout << YELLOW_TEXT << "\t                                                  Quan Ly Thiet Bi Phong Kham Rang " << RED_TEXT << "H" << ORANGE_TEXT << "I" << YELLOW_TEXT << "E" << GREEN_TEXT << "P" << BLUE_TEXT << "D" << INDIGO_TEXT << "A" << VIOLET_TEXT << "T \t" << endl;
                    cout << GREEN_TEXT << "\n                                                           =======================================================" << endl;
                    cout << GREEN_TEXT << "                                                           =                                                     =" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            1.Nhap thong tin thiet bi                " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            2.Xuat thong tin thiet bi                " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            3.Xuat file thiet bi                     " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            4.Tim kiem thiet bi theo ma TB           " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            5.Sua thong tin thiet bi                 " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            6.Xoa thong tin thiet bi                 " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            7.Them thong tin thiet bi                " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =" << YELLOW_TEXT << "            8.Quay lai menu                          " << GREEN_TEXT << "=" << endl;
                    cout << GREEN_TEXT << "                                                           =                                                     =" << endl;
                    cout << GREEN_TEXT << "                                                           =======================================================" << endl; 
                    cout << YELLOW_TEXT << "\t                                                   ====> Nhap lua chon cua ban: ";
                    cout << RESET_TEXT;
                    cin >> luachontb;
                    switch (luachontb) 
					{
                        case 1:
                            nhaptb(a, nn);
                            system("pause");
                            break;
                        case 2:
                            xuattb(a, nn);
                            system("pause");
                            break;
                        case 3:
                            xuatfileTB(a, nn);
                            system("pause");
                            break;
                        case 4:
                            timkiemtb(a, nn);
                            system("pause");
                            break;
                        case 7:
                            themtb(a, nn);
                            system("pause");
                            break;
                        case 6:
                            xoatb(a, nn);
                            system("pause");
                            break;
                        case 5:
                            suatttb(a, nn);
                            system("pause");
                            break;
                        case 8:                                                  // danh dau thoat khoi vong lap quay tro lai menu chinh 
                            break;
                        default:
                            cout << RED_TEXT << "Khong co du lieu ban nhap!";
                            cout << RESET_TEXT;
                            system("pause");
                            break;
                    }
                } while (luachontb != 8);
                break;
            case 4:
                cout <<RED_TEXT<< "Thoat khoi chuong trinh." << endl;
                cout<<RESET_TEXT;
                break;
            default:
                cout << RED_TEXT << "Khong co du lieu ban nhap!";
                cout << RESET_TEXT;
                system("pause");
                break;
        }
    } while (LUACHON != 4);
}
int main() 
{
    int n, N, nn; 
    cout <<"                                               Chao Mung Da Den Voi Chuong Trinh Quan Ly Phong Kham Rang " << RED_TEXT << "H" << ORANGE_TEXT << "I" << YELLOW_TEXT << "E" << GREEN_TEXT << "P" << BLUE_TEXT << "D" << INDIGO_TEXT << "A" << VIOLET_TEXT << "T \t" << endl;
    cout <<YELLOW_TEXT<<"\n\n\n\nNhap so luong benh nhan phong kham rang: ";
    cin >> n;
    cout <<YELLOW_TEXT<<"\nNhap so luong nhan su phong kham rang: ";
    cin >> N;
    cout <<YELLOW_TEXT<<"\nNhap so luong thiet bi phong kham rang: ";
    cin >> nn;
    quanlyphongkham* a = new quanlyphongkham[n,N,nn];              // khoi tao mang doi tuong voi kich thuoc (n: benh nhan ) va (N: nhan su) (nn: so luong thiet bi phong kham)
    menu(a,n,N,nn);                                              //goi ham menu de hien thi menu va xu ly lua chon cua nguoi dung 
    return 0;
}



