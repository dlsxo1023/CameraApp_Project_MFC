<div align="center">
<h1>📷Camera App</h1>
휴대폰 어플 SNOW카메라에 대적하는 윈도우OS 기반 카메라 APP 다양한 사진 및 동영상 편집을 사용할수 있습니다.🍀 
</div>

## 목차
  - [개요](#개요) 
  - [프로그램 설명](#프로그램-설명)
  - [구동 방식](#구동-방식)

## 개요
- 프로젝트 이름 : Rain
- 프로젝트 개발기간: 2024.02.20-2024.02.25
- 개발 툴 및 언어: MFF & OpenCV & C++
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

-뷰티 기능

|합성 기능|눈 크기 조절|
|---|---|
|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/4617b8e8-5e40-4d85-ab47-663987dd49f2)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/a1bce18c-ab8a-4115-b12c-f1e5f01eddb0)|
|Haar Cascade|Haar Cascade|


- 밝기 기능
|밝기|명암|
|---|---|
|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/7032ad18-59ba-4363-a0e1-c3e0b88ae33d)![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/d0498a63-c641-41a9-8d1a-91ea3cba924e)|![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/dabe67eb-0b9d-4e3d-b2ec-80078517053f)![image](https://github.com/dlsxo1023/CameraApp_Project_MFC/assets/149138829/91813163-eec2-4db1-beef-572e02b1a6cd)|
|cvtColor|ycrcv|


























