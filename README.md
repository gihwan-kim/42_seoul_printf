# 42_seoul_printf
This project is printf project in 42 seoul course

<img src ="https://user-images.githubusercontent.com/33623130/80716161-49bd7480-8b32-11ea-8682-2f5324b398e8.jpg"> </img>

* no_norminette_printf folder : norminette 처리 하지않은 초기 printf 소스코드
* norminette_printf folder    : norminette 처리한 printf 소스 

### Madnatory part

cspdiuxX% 만 구현  
'-0.*', minimum fieldwidth with all conversions 기능 구현  

### bonus part
nfge conversion 추가  
l ll h hh 추가  
'# +' 추가  

### printf 구현 계획
> %[flags][width][.precision][length][specifier]
```
controller -  : view, module에 실행명령을 내린다.
                1. 바로 출력 가능
                    view 실행
                2. 바로 출력 불가능
                    model 실행

module     - algorithm -> return value : 0, 1
                1. foramt 의 구역별로 에러 체크를 먼저한다.
                    1-1 현재 구역의 에러 : no
                        현재 구역의 정보를 구조체에 담으며 format 의 주소를 이동시킨다.
                    (각 구역별 options에 해당하는 문자가 없을 경우 다음 구역으로 넘어간다.)
                    (마지막 구역까지 갔을 때 options에 해당하는 문자이외의 문자가 있을 경우 에러처리한다.)
                    1-2 현재 구역의 에러 : yes
                        함수를 끝낸다.
                2. 각 구역간의 규칙을 비교 에러 체크를 한다. 어떤 에러가 있지?
                     specifier 와 다른 구역들간의 비교
                3. 출력할 문자열을 생성한다.
                     ap 와 규칙을 비교해서 만든다.
                4. 출력할 문자열을 리턴한다.
                5. 함수 끝

view       - ft_putchar_fd

             output functions


/* f_info 의 최종 문자열 포인터에 넣기 */
%[flags][width][.precision][length][specifier]

flags :
    - :
        왼쪽에서 부터 출력 시작 (default 는 오른쪽)
            s, p, c, d, i, u, x, X  가능
    0 :
        남는 공간(width)이 있을 경우(d~x : width 가 더클 경우) 0 으로 채운다 (0 없을 경우 space로 채워짐)
            p, s, c : 에러, 앞에서 처리하기 때문에 고려안해도 된다.
            d, i, u, x, X
                   - 와 같이 사용 :  0 flags가 무시됨
                   precision 존재 할경우 : 0 flags 가 무시된다.
                   -, precision, 0 같이사용 : 0 flags 가 무시된다.

                     0
                     0 -
                     0 - pre
                     0 pre
                     -
                     - pre
 '0' flag ignored with precision and ‘%d’ gnu_printf format   %0.5d

 '0' flag used with ‘%c’ gnu_printf format  %0c
width :
    (number) :
        d i u x X
             아이템len > width : 아이템 전부 출력 (길이 : 아이템len)
             아이템len < width : 아이템 전부 출력,  width 만큼 공백,  (길이 : widthlen)
                 flags 0 있을 경우 : p,s,c 를 제외하고 남는 공간은 0
             width 가 0인건 존재하지 않는다.
    *, number 확인한다.

precision :
    .만 있을 경우 : 정밀도는 0
    .(number)    :
        d i u x X :
            number > 아이템len : 아이템 len을 제외한 남는 공간은 0 으로 왼쪽에서 부터 채워진다.
            number < 아이템len : 아이템 그대로 유지
            number = 아이템len : 아이템 그대로 유지
                             0 : 아이템 그대로 유지
             widty, precision 같이 사용 가능
        s         :
            number > 아이템len : 아이템 그대로 유지
            number = 아이템len : 아이템 그대로 유지
            number < 아이템len : number 수만큼 아이템이 짤린다.
                             0 : 길이 0
        c p       : 에러, 앞에서 처리해놓기 때문에 고려안해도 됨 ? (에러 확실? 3/11 : 다시확인해볼것)
    .*           :
        ap 로부터 받아온다. 기능은 number와 동일하지만 ap 가 없을 경우 에러 체크
precision 에 맞게 해당 아이템을 수정(아이템을 직접 수정하게 되면
나중에 다시 아이템을 쓸때 문제가 생김 어떻게 할지 고민할 것)한뒤에 width 와 flags 를 적용시켜야할것 같다.
메모리를 할당한다. (width, ap의 크기에 맞게)

< 출력할 문자열(string_to_output) 생성 >
0. specifeir 와 item 형 확인
1. precision : item 의 크기결정,
2. width : item 크기와 비교 output 길이 정하기
3. 문자열 규칙에 맞게 채우기
```
