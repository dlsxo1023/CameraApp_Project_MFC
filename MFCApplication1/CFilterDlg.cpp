﻿// CFilterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CFilterDlg.h"


// CFilterDlg 대화 상자

IMPLEMENT_DYNAMIC(CFilterDlg, CDialogEx)

CFilterDlg::CFilterDlg()
	: CDialogEx(IDD_DIALOG1)
{

}

CFilterDlg::CFilterDlg(Mat Img, BITMAPINFO* bitmapInfo)
	: CDialogEx(IDD_DIALOG1)
{
	myImg = Img; // 이미지 매트릭스 정보 가져오기 
	myBitmapInfo = bitmapInfo; 
}

CFilterDlg::~CFilterDlg()
{
}

void CFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PC_FT, picCtrl_FT);
	DDX_Control(pDX, IDC_EMBOSS_FT, embossFT);
	DDX_Control(pDX, IDC_FOGLB_FT, fogLB_FT);//IDC_SLIDER_GAUSSIAN_FT
	DDX_Control(pDX, IDC_SLIDER_FOG_FT, fogslider_FT);
	DDX_Control(pDX, IDC_SHARP_SLIDER_FT, sharpSliderFT);
	DDX_Control(pDX, IDC_SHARP_FT, sharpLB_FT);
	DDX_Control(pDX, IDC_BILATERAL_FT, bilateralBtn_FT);
	DDX_Control(pDX, IDC_SLIDER_NOISE_FT, noiseFT);
	DDX_Control(pDX, IDC_NOISELB_FT, noiseLB_FT);
	DDX_Control(pDX, IDC_PARTBLUR_FT, partBlutBtn);
	DDX_Control(pDX, IDC_STATIC_POINTLOC, pointLocFT);
	DDX_Control(pDX, IDC_SLIDER_PARTBLUR, partBlurSlider);
}


BEGIN_MESSAGE_MAP(CFilterDlg, CDialogEx)
//	ON_WM_GETMINMAXINFO()
ON_BN_CLICKED(IDOK, &CFilterDlg::OnBnClickedOk)
//ON_BN_CLICKED(IDC_IMGLOAD_FT, &CFilterDlg::OnBnClickedImgloadFt)
ON_WM_TIMER()
ON_WM_DESTROY()
ON_BN_CLICKED(IDC_EMBOSS_FT, &CFilterDlg::OnBnClickedEmbossFt)
ON_BN_CLICKED(IDC_REVERT_FT, &CFilterDlg::OnBnClickedRevertFt)
ON_BN_CLICKED(IDCANCEL, &CFilterDlg::OnBnClickedCancel)
//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_FOG_FT, &CFilterDlg::OnNMCustomdrawSliderFogFt)
ON_WM_HSCROLL()
ON_BN_CLICKED(IDC_BILATERAL_FT, &CFilterDlg::OnBnClickedBilateralFt)
ON_WM_MOUSEMOVE()
//ON_WM_PAINT()
ON_BN_CLICKED(IDC_PARTBLUR_FT, &CFilterDlg::OnBnClickedPartblurFt)
//ON_WM_PAINT()
ON_WM_DRAWITEM()
ON_WM_CTLCOLOR()
ON_WM_LBUTTONDOWN()
//ON_STN_CLICKED(IDC_STATIC_POINTLOC, &CFilterDlg::OnStnClickedStaticPointloc)
END_MESSAGE_MAP()



// CFilterDlg 메시지 처리기


BOOL CFilterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(350, 140, 1280, 720);

	CRect wnd;
	this->GetClientRect(&wnd); // 기본 사각형의 x,y 좌표설정이되고 =(0,0) 시작되는함수'GetClientRect' 함수에 
	int btnLocX = int(wnd.right * 5 / 6);
	int btnLocY = 40;
	int bottom_btnLocY = wnd.bottom -40;

	embossFT.MoveWindow(btnLocX, btnLocY, 200, 45); btnLocY += 45;//1000, 40, 200, 45
	fogLB_FT.MoveWindow(btnLocX, btnLocY, 200, 20); btnLocY += 20;//1000, 105, 200, 20
	fogslider_FT.MoveWindow(btnLocX, btnLocY, 200, 20); btnLocY += 20;
	fogslider_FT.SetRange(0, 5);
	fogslider_FT.SetTicFreq(1);
	fogslider_FT.SetTic(5);
	fogslider_FT.SetPos(0);
	sharpLB_FT.MoveWindow(btnLocX, btnLocY, 200, 20); btnLocY += 20;
	sharpSliderFT.MoveWindow(btnLocX, btnLocY, 200, 20); btnLocY += 45;
	sharpSliderFT.SetRange(0, 5);
	sharpSliderFT.SetTicFreq(1);
	sharpSliderFT.SetPos(0);
	bilateralBtn_FT.MoveWindow(btnLocX, btnLocY, 200, 45); btnLocY += 45;
	noiseLB_FT.MoveWindow(btnLocX, btnLocY, 200, 20); btnLocY += 20;
	noiseFT.MoveWindow(btnLocX, btnLocY, 200, 20); btnLocY += 20;
	noiseFT.SetRange(0,100);
	noiseFT.SetTicFreq(10);
	noiseFT.SetPos(0);
	partBlutBtn.MoveWindow(btnLocX, btnLocY, 200, 45); btnLocY += 45;
	pointLocFT.MoveWindow(btnLocX, btnLocY, 200, 20); btnLocY += 20;
	partBlurSlider.MoveWindow(btnLocX, btnLocY, 200, 20); btnLocY += 20;
	partBlurSlider.SetRange(1, 5);
	partBlurSlider.SetTicFreq(1);
	partBlurSlider.SetPos(1);
	blurRangeHalfWid = 1;

	GetDlgItem(IDCANCEL)->MoveWindow(btnLocX, bottom_btnLocY, 200, 45); bottom_btnLocY -= 55;
	GetDlgItem(IDOK)->MoveWindow(btnLocX, bottom_btnLocY, 200, 45); bottom_btnLocY -= 55;
	GetDlgItem(IDC_REVERT_FT)->MoveWindow(btnLocX, bottom_btnLocY, 200, 45);
	partBlurModeOn = false;
	//DrawImage(); dialog 호출시 oninitDiaog()뒤에 실행되는 메세지들에 의하여, 사진이 출력되지 않음 
	SetTimer(1, 80, NULL);//100ms  사진 불러오기 위한 타이머 
	CDialogEx::SetBackgroundColor(0x004D3428, 1);

	CFont font;
	font.CreatePointFont(120, _T("함초롬돋움 확장 보통"));//함초롬돋움 확장 보통
	embossFT.SetFont(&font);
	fogLB_FT.SetFont(&font);
	sharpLB_FT.SetFont(&font);
	bilateralBtn_FT.SetFont(&font);
	noiseLB_FT.SetFont(&font);
	partBlutBtn.SetFont(&font);
	GetDlgItem(IDOK)->SetFont(&font);
	GetDlgItem(IDCANCEL)->SetFont(&font);
	GetDlgItem(IDC_REVERT_FT)->SetFont(&font);
	font.Detach();//font 종료 꼭 해주기 메모리 할당 해제 
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


//INT_PTR CFilterDlg::DoModal()
//{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

//	return CDialogEx::DoModal();
//}


//void CFilterDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
//{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	lpMMI->ptMinTrackSize = CPoint(1080,720);
//	lpMMI->ptMaxTrackSize = CPoint(1080,720);
//	CFilterDlg::OnGetMinMaxInfo(lpMMI);
	//CDialogEx::OnGetMinMaxInfo(lpMMI);
//}


//적용 버튼을 누르면, 창을 종료하고, 부모창에도 변경된 이미지가 보여짐 
void CFilterDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//메세지 박스 적용되었습니다 알림 넣기 
	CDialogEx::OnOK();
} 


//다이얼로그창에 사진 띄우기 
void CFilterDlg::DrawImage(Mat requestImg, BITMAPINFO* requestBmpInfo) {
	KillTimer(1);

	//필터창 크기
	CRect wnd;
	this->GetClientRect(&wnd); // 기본 사각형의 x,y 좌표설정이되고 =(0,0) 시작되는함수'GetClientRect' 함수에 
	int wx = int(wnd.right * 5 / 6);
	int wy = wnd.bottom;

	//불러올 사진 cols 가져오기.
	CClientDC dc(GetDlgItem(IDC_PC_FT)); 
	CRect rect;// 이미지를 넣을 사각형 
	if (requestImg.cols > wx) {
		//cols: 1080 = rows : wid;
		int resize_h = cvRound((wx * requestImg.rows) / requestImg.cols);
		int resize_w = wx; //width를 최대크기로 설정 
		if (wy - resize_h < 0) { //width를 맞추니, height가 넘친다 
			resize_w = wy * wx / resize_h;
		}
		int x = cvRound((wx - resize_w) / 2);
		int y = cvRound((wy - resize_h) / 2);
		GetDlgItem(IDC_PC_FT)->MoveWindow(x, y, resize_w, resize_h);
		picLTRB.left = x; picLTRB.top = y;
		picLTRB.right = resize_w; picLTRB.bottom = resize_h;
	}
	else {
		int x = cvRound((wx - requestImg.cols) / 2);
		int y = cvRound((wy - requestImg.rows) / 2);
		GetDlgItem(IDC_PC_FT)->MoveWindow(x, y, requestImg.cols, requestImg.rows);
		picLTRB.left = x; picLTRB.top = y;
		picLTRB.right = x + requestImg.cols; picLTRB.bottom = y+ requestImg.rows;
	}


	//GetClientRect(left, top, right, bottom ) 클라이언트 영역의 좌표
	//함수가 성공하면 반환 값이 0이 아닙니다.
	//불러올 이미지 사진에 따라 조정된 Picture Ctrl 크기 
	GetDlgItem(IDC_PC_FT)->GetClientRect(&rect);

	//픽셀을 삭제합니다. 이 모드는 해당 정보를 보존하지 않고 
	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);

	//StretchDIBits 함수는 DIB, JPEG 또는 PNG 이미지의 픽셀 사각형에 
	// 대한 색 데이터를 지정된 대상 사각형에 복사합니다.
	//dc.GetSafeHdc(): 출력 디바이스 컨텍스트를 가져옵니다
	// 함수가 성공하면 반환 값은 복사된 검사 줄의 수입니다. 이 값은 미러된 콘텐츠에 대해 음수일 수 있습니다.
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, requestImg.cols, requestImg.rows, requestImg.data, requestBmpInfo, DIB_RGB_COLORS, SRCCOPY);
}

//void CFilterDlg::OnBnClickedImgloadFt()
//{
	// TODO: Add your control notification handler code here
//	DrawImage();
//}


void CFilterDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent) {
	case 1:
		//처음 다이얼로그 창을 띄울 때 onInitDialog()에서 drawimage가 이후 
		// 자동 수행되는 메시지 함수에의해서 출력이 안되서 
		//onInitDialog()에 타이머로 걸어놓음  
		DrawImage(myImg, myBitmapInfo);//처음 로딩되는 이미지 
		break;
	
	}
	CDialogEx::OnTimer(nIDEvent);
}

//윈도우 창이 DESTORY 갑자기 종료될때, 저장해야 하는 정보들 기능 수행
void CFilterDlg::OnDestroy() 
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
}

//진흙필터 :1채널 필터링 : grayscale이미지로 변환 필요 
void CFilterDlg::OnBnClickedEmbossFt()//1채널 필터링 
{
	// TODO: Add your control notification handler code here
	colorToGray();//color 사진의 경우 gray로 변경. 

	float data[] = { -1,-1,0,-1,0,1,0,1,1 };
	Mat emboss(3, 3, CV_32FC1, data);

	Mat dst;
	filter2D(myImgAfterChange, dst, -1, emboss, Point(-1, -1), 128);
	myImgAfterChange = dst;
	DrawImage(myImgAfterChange, myBmpInfoAfterChange);
}

//컬러(채널3)를 그레이(채널1)로 변경 
BOOL CFilterDlg::colorToGray()
{
	// TODO: Add your implementation code here.
	//현재 채널 정보를 확인해서 gray가 아닐 경우
	if (myImg.channels() != 1) {
		cvtColor(myImg, myImgAfterChange, COLOR_BGR2GRAY);
		CreateBitmapInfo(&myBmpInfoAfterChange, myImgAfterChange.cols, myImgAfterChange.rows, myImgAfterChange.channels() * 8);
		return true; 
	}
	return false; 
}


//BITMAP 정보 구조체 데이터 생성 
void CFilterDlg::CreateBitmapInfo(BITMAPINFO** btmInfo, int w, int h, int bpp){
	if (*btmInfo != NULL) //기존 비트맵 정보 초기화 
	{
		delete *btmInfo;
		*btmInfo = NULL; //기존 BITMAP 정보 삭제 
	}

	if (bpp == 8) //1채널 
		*btmInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24(3채널) or 32bit(4채널)
		*btmInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	(*btmInfo)->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//구조체에 필요한 바이트 수
	(*btmInfo)->bmiHeader.biPlanes = 1;// 대상 디바이스의 평면 수를 지정합니다. 이 값은 1로 설정해야 합니다.
	(*btmInfo)->bmiHeader.biBitCount = bpp;//픽셀당 비트 수(bpp)를 지정합니다. 압축되지 않은 형식의 경우 이 값은 픽셀당 평균 비트 수입니다.
	(*btmInfo)->bmiHeader.biCompression = BI_RGB;//압축되지 않은 RGB.
	(*btmInfo)->bmiHeader.biSizeImage = 0;//이미지의 크기(바이트)를 지정합니다.
	(*btmInfo)->bmiHeader.biXPelsPerMeter = 0;//비트맵에 대한 대상 디바이스의 가로 해상도(미터당 픽셀)
	(*btmInfo)->bmiHeader.biYPelsPerMeter = 0;//비트맵에 대한 대상 디바이스의 세로 해상도(미터당 픽셀)를 지정합니다.
	(*btmInfo)->bmiHeader.biClrUsed = 0;//비트맵에서 실제로 사용되는 색 테이블의 색 인덱스 수를 지정합니다.
	(*btmInfo)->bmiHeader.biClrImportant = 0;//비트맵을 표시하는 데 중요한 것으로 간주되는 색 인덱스의 수를 지정합니다.이 값이 0이면 모든 색이 중요합니다.

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			(*btmInfo)->bmiColors[i].rgbBlue = (BYTE)i;
			(*btmInfo)->bmiColors[i].rgbGreen = (BYTE)i;
			(*btmInfo)->bmiColors[i].rgbRed = (BYTE)i;
			(*btmInfo)->bmiColors[i].rgbReserved = 0;
		}
	}

	(*btmInfo)->bmiHeader.biWidth = w;
	(*btmInfo)->bmiHeader.biHeight = -h;//음수는 원본이 왼쪽 위 모서리에 있는 하향식 DIB입니다.
}

//되돌리기 기능 (원본 이미지로 돌아감) 
void CFilterDlg::OnBnClickedRevertFt()
{
	// TODO: Add your control notification handler code here
	DrawImage(myImg, myBitmapInfo);
	myImgAfterChange = myImg.clone();
	myBmpInfoAfterChange = myBitmapInfo;
	MessageBox(L"원본으로 돌아갑니다", L"알림",MB_OK);
}

//필터 창을 종료하고, 부모창 사진에는 변경이 안되어 있어야함. 
void CFilterDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


//void CFilterDlg::OnNMCustomdrawSliderFogFt(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
//	int sigma = fogslider_FT.GetPos();
//
//	GaussianBlur(myImg, myImgAfterChange, Size(), (double)sigma);
//	CreateBitmapInfo(&myBmpInfoAfterChange, myImgAfterChange.cols, myImgAfterChange.rows, myImgAfterChange.channels() * 8);
//	DrawImage(myImgAfterChange, myBmpInfoAfterChange);
//	*pResult = 0;
//}


//트랙바 조절에 따른 처리 기능 
//각 필터의 강도 조절 
void CFilterDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	if (*pScrollBar == fogslider_FT) {
		int sigma = fogslider_FT.GetPos();
		if (sigma != 0) {
			GaussianBlur(myImg, myImgAfterChange, Size(), (double)sigma);
			CreateBitmapInfo(&myBmpInfoAfterChange, myImgAfterChange.cols, myImgAfterChange.rows, myImgAfterChange.channels() * 8);
			DrawImage(myImgAfterChange, myBmpInfoAfterChange);
		}
	}
	else if (*pScrollBar == sharpSliderFT) {

		int sigma = sharpSliderFT.GetPos();
		if (sigma != 0) {
			GaussianBlur(myImg, myImgAfterChange, Size(), (double)sigma);
			float alpha = 1.f;
			Mat dst = (1 + alpha) * myImg - alpha * myImgAfterChange;
			myImgAfterChange = dst;
			CreateBitmapInfo(&myBmpInfoAfterChange, myImgAfterChange.cols, myImgAfterChange.rows, myImgAfterChange.channels() * 8);
			DrawImage(myImgAfterChange, myBmpInfoAfterChange);
		}
	}
	else if (*pScrollBar == noiseFT) {
		colorToGray();//그레이스케일 이미지로 변환  
		int stddev = noiseFT.GetPos();
		Mat noise(myImgAfterChange.size(), CV_32SC1);
		randn(noise, 0, stddev);

		Mat dst;
		add(myImgAfterChange, noise, dst, Mat(), CV_8U);
		myImgAfterChange = dst;
		DrawImage(myImgAfterChange, myBmpInfoAfterChange);
	}
	else if (*pScrollBar == partBlurSlider) {
		blurRangeHalfWid = partBlurSlider.GetPos();
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

//양방향필터 
void CFilterDlg::OnBnClickedBilateralFt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	colorToGray();//color 사진의 경우 gray로 변경.
	Mat dst;
	bilateralFilter(myImgAfterChange, dst, -1, 10, 5); // -1 sigmaSpace로부터 자동생성됨. 10: 색공간에서의 가우시안 표준 편차 5: 좌표 공간에서의 가우시안 표준편차 
	myImgAfterChange = dst;
	DrawImage(myImgAfterChange, myBmpInfoAfterChange);
}


void CFilterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//if (partBlurModeOn) {
	//	
	//	// TODO: Add your message handler code here
	//	circlePos.x += point.x - prev_mousePos.x;
	//	circlePos.y += point.y - prev_mousePos.y;
	//	prev_mousePos = point;
	//	Invalidate();
	//}

	CDialogEx::OnMouseMove(nFlags, point);
}


//void CFilterDlg::OnPaint()
//{
	//if (IsIconic())
	//{
	//	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	//	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	//}
	//else
	//{
	//	CPaintDC dc(this);
	//	CRect wnd;
	//	this->GetWindowRect(wnd);// right:창의 너비 bottm: 창의 높이 
	//	int xloc = int(wnd.right * 5 / 6);
	//	int backImgWid = int(wnd.right * 1 / 6);
	//	dc.FillSolidRect(xloc, 0, backImgWid, wnd.bottom, RGB(40, 56, 84));//35, 47, 69
	//	//CDialogEx::OnPaint();
	//}
//}


void CFilterDlg::OnBnClickedPartblurFt()
{
	//// TODO: Add your control notification handler code here
	partBlurModeOn = !partBlurModeOn;
	
}



//버튼 컬러 구현 
void CFilterDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nIDCtl) {
		case IDC_PARTBLUR_FT:
		{
			if (lpDrawItemStruct->itemAction & 0x07) {
				CDC* p_dc = CDC::FromHandle(lpDrawItemStruct->hDC);
				if (lpDrawItemStruct->itemState && ODS_SELECTED && partBlurModeOn == false) {//버튼 클릭시 
					p_dc->FillSolidRect(&lpDrawItemStruct->rcItem, RGB(60, 75, 105));//버튼의 색상
					p_dc->Draw3dRect(&lpDrawItemStruct->rcItem, RGB(42, 52, 71), RGB(42, 52, 71));//버튼 외곽선
					p_dc->SetTextColor(RGB(171, 182, 199));
				}
				else {//기본 상태  //&lpDrawItemStruct->rcItem 버튼의 크기
					p_dc->FillSolidRect(&lpDrawItemStruct->rcItem, RGB(42, 52, 71));//버튼의 색상
					p_dc->Draw3dRect(&lpDrawItemStruct->rcItem, RGB(60, 75, 105), RGB(60, 75, 105));//버튼 외곽선
					p_dc->SetTextColor(RGB(140, 147, 161));
				}

				p_dc->SetBkMode(TRANSPARENT);
			}break;
		}
		case IDC_EMBOSS_FT: case IDC_BILATERAL_FT:
		case IDC_REVERT_FT:
		case IDOK: case IDCANCEL: {
			if (lpDrawItemStruct->itemAction & 0x07) {
				CDC* p_dc = CDC::FromHandle(lpDrawItemStruct->hDC);
				if (lpDrawItemStruct->itemState && ODS_SELECTED) {//버튼 클릭시 
					p_dc->FillSolidRect(&lpDrawItemStruct->rcItem, RGB(60, 75, 105));//버튼의 색상
					p_dc->Draw3dRect(&lpDrawItemStruct->rcItem, RGB(42, 52, 71), RGB(42, 52, 71));//버튼 외곽선
					p_dc->SetTextColor(RGB(171, 182, 199));
				}
				else {//기본 상태  //&lpDrawItemStruct->rcItem 버튼의 크기
					p_dc->FillSolidRect(&lpDrawItemStruct->rcItem, RGB(42, 52, 71));//버튼의 색상
					p_dc->Draw3dRect(&lpDrawItemStruct->rcItem, RGB(60, 75, 105), RGB(60, 75, 105));//버튼 외곽선
					p_dc->SetTextColor(RGB(140, 147, 161)); 
					
				}

				p_dc->SetBkMode(TRANSPARENT);
			}break;
		}
		default: break;
	}
	CDC* p_dc = CDC::FromHandle(lpDrawItemStruct->hDC);
	switch (nIDCtl) {
	case IDC_EMBOSS_FT: {
		p_dc->DrawText(L"진흙필터", -1, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	}
	case IDC_BILATERAL_FT: {
		p_dc->DrawText(L"양방향필터", -1, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	}
	case IDC_PARTBLUR_FT: {
		if (partBlurModeOn ==true) {
			p_dc->DrawText(L"부분블러ON", -1, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;
		}
		else {
			p_dc->DrawText(L"부분블러OFF", -1, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;
		}

		
	}
	case IDC_REVERT_FT: {
		p_dc->DrawText(L"되돌리기", -1, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	}
	case IDOK: {
		p_dc->DrawText(L"저장", -1, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	}
	case IDCANCEL: {
		p_dc->DrawText(L"취소", -1, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	}
	default: break;
	}
	//CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}


HBRUSH CFilterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	int staticLb = pWnd->GetDlgCtrlID(); 
	switch (staticLb) {//라벨의 텍스트 컬러를 변경합니다 
		case IDC_FOGLB_FT: case IDC_SHARP_FT:
		case IDC_NOISELB_FT: case IDC_REVERT_FT: 
		case IDC_STATIC_POINTLOC:
		pDC->SetTextColor(RGB(171, 182, 199));
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CFilterDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//1. IDC_STATIC_POINTLOC  위치 조정.
	//	1. LBUTTON DOWN >> CPOINT  값을 가져옴
	//	2. IDC_STATIC_POINTLOC >> 현재 위치 출력
	if (partBlurModeOn ==true) {//부분 블러 모드 버튼을 클릭했을 때 
		blurLoc = point;//누른 지점을 저장한다
		CString loc;
		loc.Format(_T("point x: %u y: %u"), point.x, point.y);
		SetDlgItemText(IDC_STATIC_POINTLOC, (LPCTSTR)loc);
		partBlurProc(point);
		DrawImage(myImgAfterChange, myBmpInfoAfterChange);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


//블러 처리 : 컬러영상에 대한 / 흑백영상은 추후 구현 
//평균값 마스크: 3x3 1/9 필터 
void CFilterDlg::partBlurProc(CPoint point) {
	//1. 마우스 포인터 위치값으로, 이미지상의 실제 위치를 계산한다 
	// picLTRB에는 마지막 draw 했을 때의 rect 정보가 담김
	CPoint locInImg;//본인 창에서의 이미지 위치 x= left, y =top 
	locInImg.x = point.x - picLTRB.left;// 
	locInImg.y = point.y - picLTRB.top;
	//진흙필터 >되돌리기> 부분블러 ON > 에러 
	//range 범위가 벗어낫을 때 에러 
	CRect blurArea;//이미지 공간 안에서의 블러 영역 
	int range = blurRangeHalfWid*50;
	blurArea.left = locInImg.x - range; blurArea.top = locInImg.y - range;
	blurArea.right = locInImg.x + range; blurArea.bottom = locInImg.y + range;
	if (blurArea.left < 0) { blurArea.left = 0; }
	if(blurArea.top <0) { blurArea.top = 0; }
	if (blurArea.right > picLTRB.right- picLTRB.left) { 
		blurArea.right = picLTRB.right - picLTRB.left-1; }
	if (blurArea.bottom > picLTRB.bottom - picLTRB.top) {
		blurArea.bottom = picLTRB.bottom - picLTRB.top-1;	}

	Mat src;
	if (myImgAfterChange.data == NULL) {//아무것도 저장되어 있지 않는 상태 
		myImgAfterChange = myImg.clone();
		src = myImg.clone();
	}
	else {
		src = myImgAfterChange.clone(); 
	}
	for (int y = blurArea.top; y <= blurArea.bottom; y++) {
		for (int x = blurArea.left; x <= blurArea.right; x++) {
			if(x-1<1||y-1<1||x+1>blurArea.right||y+1>blurArea.bottom){
				continue;
			}
			Vec3b& p1 = src.at<Vec3b>(y - 1, x - 1);
			Vec3b& p2 = src.at<Vec3b>(y - 1, x);
			Vec3b& p3 = src.at<Vec3b>(y - 1, x + 1);
			Vec3b& p4 = src.at<Vec3b>(y, x - 1);
			Vec3b& p5 = src.at<Vec3b>(y, x);
			Vec3b& p6 = src.at<Vec3b>(y, x + 1);
			Vec3b& p7 = src.at<Vec3b>(y + 1, x - 1);
			Vec3b& p8 = src.at<Vec3b>(y + 1, x);
			Vec3b& p9 = src.at<Vec3b>(y+1, x+1);

			Vec3b& dst = myImgAfterChange.at<Vec3b>(y, x);
			//dst[0] = 0;
			//dst[1] = 0;
			//dst[2] = 0;

			//b
			dst[0] = int(cvRound((p1[0] + p2[0] + p3[0] + p4[0] +
				p5[0] + p6[0] + p7[0] + p8[0] + p9[0])/9));
			int b = dst[0];
			//g
			dst[1] = int(cvRound((p1[1] + p2[1] + p3[1] + p4[1] +
				p5[1] + p6[1] + p7[1] + p8[1] + p9[1])/9));
			int g = dst[1];
			//r
			dst[2] = int(cvRound((p1[2] + p2[2] + p3[2] + p4[2] +
				p5[2] + p6[2] + p7[2] + p8[2] + p9[2])/ 9));
			int r = dst[2];
		}
	}
	CreateBitmapInfo(&myBmpInfoAfterChange, myImgAfterChange.cols, myImgAfterChange.rows, myImgAfterChange.channels() * 8);
	
}


//void CFilterDlg::OnStnClickedStaticPointloc()
//{
//	// TODO: Add your control notification handler code here
//}
