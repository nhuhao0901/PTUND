// Lab01_4501104071_LeNguyenNhuHao.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
const int MAX = 100; //so dinh toi da cua do thi

//Do thi gom co so dinh va ma tran ke. 
struct GRAPH
{
	int sodinh;//so dinh do thi
	int a[MAX][MAX];//ma tran ke
};
//Ham doc du lieu len tu file
void readGRAPH(GRAPH& g)
{
	cin >> g.sodinh;
	for (int i = 0; i < g.sodinh; i++)
		for (int j = 0; j < g.sodinh; j++)
			cin >> g.a[i][j];
}
//Ham xuat ma tran ke
void printGRAPH(GRAPH g)
{
	cout << "So dinh cua do thi: " << g.sodinh << endl;
	for (int i = 0; i < g.sodinh; i++)
	{
		for (int j = 0; j < g.sodinh; j++)
			cout << setw(4) << g.a[i][j];
		cout << endl;
	}
}
//Kiểm tra tính hợp lệ của đồ thị (giá trị trên đường chéo chính bằng 0).
int KiemTraMaTranKeHopLe(GRAPH& g)
{
	// kiểm tra các giá trị a[0][0], a[1][1], … xem có giá trị khác 0 hay không
	// nếu có, nghĩa là ma trận kề không hợp lệ
	int i;
	for (i = 0; i < g.sodinh; i++)
		if (g.a[i][i] != 0)
			return 0;
	return 1;
}

//Cho biết đồ thị có hướng hay vô hướng?
int KiemTraDoThiVoHuong(GRAPH& g)
{
	// kiểm tra xem các giá trị a[i][j] có bằng với a[j][i] hay không
	// nếu có, nghĩa là đồ thị không đối xứng
	int i, j;
	for (i = 0; i < g.sodinh; i++)		// có thể giảm bớt các bước kiểm tra thừa với
		for (j = 0; j < g.sodinh; j++)		// for (j=i+1; j<n; j++)
			if (g.a[i][j] != g.a[j][i])
				return 0;

}
//Socanh
int getSoCanh(GRAPH& g) {
	int tongcanh = 0;
	int i, j;
	for (i = 0; i < g.sodinh; i++) {	// có thể giảm bớt các bước kiểm tra thừa với
		for (j = 0; j < g.sodinh; j++) {		// for (j=i+1; j<n; j++)
			if (g.a[i][j] != 0) {
				tongcanh++;
			}
		}
	}
	if (KiemTraDoThiVoHuong(g))
		return tongcanh / 2;
	return tongcanh;
}

//ho tro cau tim so luong trong mang
GRAPH g;
int bacCH[100];
int bacVH[100];
//Bac dinh DTVH
void getBacCuaDinhDTVH(GRAPH g) {
	for (int i = 0; i < g.sodinh; i++) {
		int sodinh = 0;
		//duyet theo tung dinh
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0) {
				sodinh++;
				bacVH[i] = sodinh;
			}
		}
		cout << "Dinh thu " << i << " bac " << bacVH[i] << endl;
	}
}
//Bac cua dinh DTCH
void getBacCuaDinhDTCH(GRAPH  g) {
	int n = 0;
	for (int i = 0; i < g.sodinh; i++) {
		int bacngoai = 0;
		int bactrong = 0;
		//duyet theo tung dinh
		for (int j = 0; j < g.sodinh; j++) {
			if (g.a[i][j] != 0) {
				bacngoai++;
			}
			if (g.a[j][i] != 0) {
				bactrong++;
			}
		}
		bacCH[n] = bacngoai + bactrong;
		n++;
	}
	for (int i = 0; i < n; i++) {
		cout << "Dinh thu " << i << " bac " << bacCH[i] << endl;
	}
}

//Max-Min
//CÁCH TAO SUY NGHĨ NÈ, K HIỂU S CHẠY K ĐƯỢC!!!!
void MaxMin(GRAPH& g) {
	if (!KiemTraDoThiVoHuong) {
		int max = bacCH[0];
		int min = bacCH[0];
		for (int i = 1; i < g.sodinh; i++) {
			if (bacCH[i] > max) max = bacCH[i];
			if (bacCH[i] < min) min = bacCH[i];
		}
		cout << "Cac dinh co bac lon nhat: ";
		for (int i = 0; i < g.sodinh; i++) {
			if (bacCH[i] == max) cout << i << " ";
		}
		cout << "\nCac dinh co bac nho nhat: ";
		for (int i = 0; i < g.sodinh; i++) {
			if (bacCH[i] == min) cout << i << " ";
		}
		exit(0);
	}
	else {
		int max = bacVH[0];
		int min = bacVH[0];
		for (int i = 1; i < g.sodinh; i++) {
			if (bacVH[i] > max) max = bacVH[i];
			if (bacVH[i] < min) min = bacVH[i];
		}
		cout << "Cac dinh co bac lon nhat: ";
		for (int i = 0; i < g.sodinh; i++) {
			if (bacVH[i] == max) cout << i << " ";
		}
		cout << "\nCac dinh co bac nho nhat: ";
		for (int i = 0; i < g.sodinh; i++) {
			if (bacVH[i] == min) cout << i << " ";
		}
		exit(0);
	}
}
/*void BacMax_Min_DTCH(GRAPH& g) {
	int max = bacCH[0];
	int min = bacCH[0];
	for (int i = 1; i < g.sodinh; i++) {
		if (bacCH[i] > max) max = bacCH[i];
		if (bacCH[i] < min) min = bacCH[i];
	}
	cout << "Cac dinh co bac lon nhat: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacCH[i] == max) cout << i << " ";
	}
	cout << "\nCac dinh co bac nho nhat: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacCH[i] == min) cout << i << " ";
	}
}
void BacMax_Min_DTVH(GRAPH& g)
{

	int max = bacVH[0];
	int min = bacVH[0];
	for (int i = 1; i < g.sodinh; i++) {
		if (bacVH[i] > max) max = bacVH[i];
		if (bacVH[i] < min) min = bacVH[i];
	}
	cout << "Cac dinh co bac lon nhat: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacVH[i] == max) cout << i << " ";
	}
	cout << "\nCac dinh co bac nho nhat: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacVH[i] == min) cout << i << " ";
	}
	exit(0);
}*/
//Chan-le
/*void BacChan_le_DTVH(GRAPH& g) {
	cout << "\nCac dinh bac chan: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacVH[i] % 2 == 0) cout << i << " ";
	}
	cout << "\nCac dinh bac le: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacVH[i] % 2 != 0) cout << i << " ";
	}
}
void BacChan_le_DTCH(GRAPH& g) {
	cout << "\nCac dinh bac chan: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacCH[i] % 2 == 0) cout << i << " ";
	}
	cout << "\nCac dinh bac le: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacCH[i] % 2 != 0) cout << i << " ";
	}
}
//Dinh treo- dinh co lap
void Dinhtreo_colap_DTVH(GRAPH& g) {
	cout << "\nCac dinh treo: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacVH[i] == 1) cout << i << " ";
	}
	cout << "\nCac dinh co lap: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacVH[i] == 0) cout << i << " ";
	}
}
void Dinhtreo_colap_DTCH(GRAPH& g) {
	cout << "\nCac dinh treo: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacCH[i] == 1) cout << i << " ";
	}
	cout << "\nCac dinh co lap: ";
	for (int i = 0; i < g.sodinh; i++) {
		if (bacCH[i] == 0) cout << i << " ";
	}
}
*/
int main()
{
	GRAPH g;
	readGRAPH(g);
	printGRAPH(g);

	if (!KiemTraMaTranKeHopLe(g)) {
		cout << "Ma tran ke khong hop le" << endl;
		exit(0);
	}
	else cout << "Ma tran hop le" << endl;

	if (KiemTraDoThiVoHuong(g)) {
		cout << "Do thi vo huong" << endl;
		cout << "Tong canh: " << getSoCanh(g) << endl;
		getBacCuaDinhDTVH(g);
		//BacMax_Min_DTVH(g);
		MaxMin(g);
		//BacChan_le_DTVH(g);
		//Dinhtreo_colap_DTVH(g);
	}
	else {
		cout << "Do thi co huong" << endl;
		cout << "Tong canh: " << getSoCanh(g) << endl;
		getBacCuaDinhDTCH(g);
		//BacMax_Min_DTCH(g);
		MaxMin(g);
		//BacChan_le_DTCH(g);
		//Dinhtreo_colap_DTCH(g);
	}
	return 0;
}

//DTCH
/*
4
0 0 1 2
2 0-3 0
0 0 0 4
0 0 0 0
*/
//DTVH
/*
5
0 2 0 4 0
2 0 -3 1 2
0 -3 0 2 2
4 1 2 0 0
0 2 2 0 0
*/