<div align="center">
<h1>📷Camera App</h1>
휴대폰 어플 SNOW카메라에 대적하는 윈도우OS 기반 카메라 APP 다양한 사진 및 동영상 편집을 사용할수 있습니다.🍀 
</div>



> Github 링크 👇

* [Github 클릭](https://github.com/dlsxo1023/CameraApp_Project_MFC)

## 목차
  - [개요](#개요) 
  - [프로그램 설명](#프로그램-설명)
  - [구동 방식](#구동-방식)

## 개요
- 프로젝트 이름 : Rain
- 프로젝트 개발기간: 2024.02.20-2024.02.25
- 개발 툴 및 언어: MFC & OpenCV & C++
- 멤버: 팀 신동희(송인태, 김경태, 장동혁, 강유진)

## 프로그램 설명
![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/be0d4580-5b66-4e31-872c-8c6d2b425e3d)
![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/5939497c-c3db-4661-afbf-7ab2ad945cb2)

|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/a4686954-b015-4d51-bea4-0465ef85b1c1)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/9d7447fb-d5bd-45c5-b563-50994a8e3f1c)|
|:---:|:---:|
|시작 화면|목록 화면|


## 구동 방식
- 필터링 기능 

|진흙필터|양방향 필터|안개필터|샤프닝 필터|노이즈 필터|부분 블러|
|---|---|---|---|---|---|
|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/d24cb4dc-c614-4734-b9f7-1d18258b679a)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/a983a507-9713-42ba-a6dd-ca93b99d566b)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/64a5b2b0-2955-4775-afe8-8c39f3fcca6a)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/0bb62c63-8ac2-4a47-b575-af62fc488e2e)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/a9cc22d7-c629-4314-8588-6551d63db8f6)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/f2dc3e94-1055-4172-a229-e8f3b6b65f96)|
|emboss|bilateralFilter|GaussianBlur|GaussianBlur|randn|blur|

- 컬러링 기능

|색 추출|색 변환|채도 변환|
|---|---|---|
|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/a526c71d-1c9a-45ef-8e12-3847b355a74c)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/4e683a5d-3a83-459f-9cb0-71272aac970a)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/bf3e7a96-19e0-4056-80ca-e88c7db2419e)|
|HBRUSH|HSV|HSV|

- 어파인 기능 

|시계/반시계 방향 회전|좌우 반전|크기조절|
|---|---|---|
|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/1aea1d57-a826-4834-8ed8-99c488512201)![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/c15d023a-bea7-49e2-8be2-9518e241b808)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/1b7a4715-69c5-438a-a612-c978b4760e98)![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/d6df8c25-ab66-455d-bb28-fa16a370097a)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/93023c20-79dd-4d63-9475-c306732be0b6)![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/32f42d64-12cf-4534-900c-0f196a10921a)|
|rotate|flip|resize|

- 뷰티 기능

|합성 기능|눈 크기 조절|
|---|---|
|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/4617b8e8-5e40-4d85-ab47-663987dd49f2)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/a1bce18c-ab8a-4115-b12c-f1e5f01eddb0)|
|Haar Cascade|Haar Cascade|


- 밝기 기능

|밝기|명암|
|---|---|
|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/7032ad18-59ba-4363-a0e1-c3e0b88ae33d)![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/d0498a63-c641-41a9-8d1a-91ea3cba924e)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/dabe67eb-0b9d-4e3d-b2ec-80078517053f)![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/91813163-eec2-4db1-beef-572e02b1a6cd)|
|cvtColor|ycrcv|

- 동영상에서 필터링

|진흙|양방향|부분 블러|노이즈|
|---|---|---|---|
|![KakaoTalk_20240327_044212513](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/15079c95-a265-491f-afee-f0186e015cc5)|![KakaoTalk_20240327_044211829](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/e8284599-cde1-4629-9a91-7ce8cc9ea860)|![KakaoTalk_20240327_044211162](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/a4e087b4-2871-4086-a72e-2df66f37430f)|![KakaoTalk_20240327_044210528](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/38cba7cf-2c73-4df3-ae13-cdc618ed3a19)|

## 주요 함수
- BitmapInfo💻<br>

|파일 구조|설명|
|---|---|
|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/383f8bbb-af33-491a-8dd8-559efe1ba38c)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/4e7fe94f-5cb6-403c-b0f8-02a133c3f359)|


```c
//#비트맵인포 BITMAP 정보 구조체 데이터 생성 
void CMFCApplication1Dlg::CreateBitmapInfo(int w, int h, int bpp) {
	if (m_pBitmapInfo != NULL) //기존 비트맵 정보 초기화 
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL; //기존 BITMAP 정보 삭제 
	}

	if (bpp == 8) //1채널 
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD)];
	else // 24(3채널) or 32bit(4채널)
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//구조체에 필요한 바이트 수
	m_pBitmapInfo->bmiHeader.biPlanes = 1;// 대상 디바이스의 평면 수를 지정합니다. 이 값은 1로 설정해야 합니다.
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;//픽셀당 비트 수(bpp)를 지정합니다. 압축되지 않은 형식의 경우 이 값은 픽셀당 평균 비트 수입니다.
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;//압축되지 않은 RGB.
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;//이미지의 크기(바이트)를 지정합니다.
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;//비트맵에 대한 대상 디바이스의 가로 해상도(미터당 픽셀)
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;//비트맵에 대한 대상 디바이스의 세로 해상도(미터당 픽셀)를 지정합니다.
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;//비트맵에서 실제로 사용되는 색 테이블의 색 인덱스 수를 지정합니다.
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;//비트맵을 표시하는 데 중요한 것으로 간주되는 색 인덱스의 수를 지정합니다.이 값이 0이면 모든 색이 중요합니다.
	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	//음수는 원본이 왼쪽 위 모서리에 있는 하향식 DIB입니다.
}
```
























