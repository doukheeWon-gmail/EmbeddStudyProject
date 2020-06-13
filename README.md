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
```