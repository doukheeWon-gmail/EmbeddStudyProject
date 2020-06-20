# Embedd Study menuconfig Project 

make menuconfig를 사용하여 샘플 코드 빌드 가능
make flashloader를 사용하여 다운로드 가능(기능은 download.sh의 함수를 이용하여 업로드)


## menuconfig 방식을 채택 (Linux , mac 사용 가능)

### 필요한 라이브러리
```
1. build-essential
2. libncurses5-dev
3. libelf-dev
4. libssl-dev
5. bison
6. flex
7. arm-none-eabi-gcc 
 - cross complier 
8. make
```


### 실행 명령어

```
make menuconfig
 - 어떤 챕터의 어떤 것을 bin 파일로 만들 것인지 설정 가능
make minicom
 - 미니컴 실행
make flashLoader
 - flashLoader로 다운로드 가능
make version
 - 현재 챕터를 추가하고 있는 버전
make clean
 - 생성이된 목정 파일인 .o 파일 및 .bin 파일 삭제
 - 설정은 그대로 남는다.
make distclean
 - 모든 파일 지우기
 - Kconfig 설정 파일도 다지운다.
make help
 - 명령어 확인 가능 사용 가능한 make 명령어 정리
```

