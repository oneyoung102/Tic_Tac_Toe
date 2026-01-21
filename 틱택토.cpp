#include <stdio.h>
#include <cstdlib>
#include <ctime>

int f_tictacto();                                                                                                         //함수
int s_tictacto();
int board();
int tic_select();

int tic_ai();

int final();
int finale();

char choi[9]= {' ', };                                                                                                    //문자
char start=0;
int select1=0;
int diff=0;
int i;
int ran;

int choi_exc=0;
int str_era=0;



int main() {                                                                                                              //메인
First:                                                                                                                    //시작
    printf("         TIC TAC TOE\n--------------------------------\n(시작하려면 아무 숫자나 누르세요)\n");
    scanf("%d", &start);
    if(start>=0||start<0) {
        start=0;
        srand((unsigned int)time(NULL));
        if(rand()%50<=49&&rand()%50>=1) {                                                                                 //이스터애그1
Start :
            printf("\n             메뉴\n-------------------------------\n(게임 선택 : 1) (게임 설명 : 2)\n") ;
            scanf("%d", &start);                                                                                              //선택
            if(start==1) {
                start=0;                                                                                                      // 게임  선택
                printf("\n                 게임  선택\n----------------------------------------------\n(하급 : 1) (상급 : 2) (PvP : 3)  (돌아가기 : 4)\n\n");
                scanf("%d",&diff);
                if(diff==1||diff==2) {                                                                                        // 게임 시작
                    tic_select();
                }
                else if(diff==4) {
                    if(str_era==7){
                    	printf("\n수상한 지우개를 주머니에서 발견했다. (수상한 지우개 +1)\n\n");
					}
					else{
						str_era+=1;
					}
					goto Start;
                }
                else if(diff==3) {                                                                                            //PvP
                    select1=0;
                    printf("\n----------------------------\n         게임 : PvP\n----------------------------\n");
                    while(1) {
                        board();
game1 :
                        printf("\nO차례입니다. 칸을 선택하세요 (무작위 선택 : 0)\n\n");
                        scanf("%d",&select1);
                        if(select1<=9&&select1>=1) {
                            if(choi[select1]!='o'&&choi[select1]!='x') {
                                choi[select1]='o';
                                select1=0;
                                final();
                            }
                            else {
                                printf("\n올바른 값을 입력하세요\n");
                                select1=0;
                                goto game1;
                            }

                            board();
game2 :
                            printf("\nX차례입니다. 칸을 선택하세요 (무작위 선택 : 0)\n\n");
                            scanf("%d",&select1);
                            if(select1<=9&&select1>=1) {
                                if(choi[select1]!='o'&&choi[select1]!='x') {
                                    choi[select1]='x';
                                    select1=0;
                                    final();
                                    printf("----------------------------");
                                }
                                else {
                                    printf("\n올바른 값을 입력하세요\n");
                                    select1=0;
                                    goto game2;
                                }
                            }
                            else if (select1==0) {
                                srand((unsigned int)time(NULL));
                                ran=rand()%9+1;
                                if(choi[ran]=='o'||choi[ran]=='x') {
                                    while(choi[ran]=='o'||choi[ran]=='x') {
                                        srand((unsigned int)time(NULL));
                                        ran=rand()%9+1;
                                    }
                                    choi[ran]='x';
                                }
                                else {
                                    choi[ran]='x';
                                }
                                select1=0;
                                final();
                                printf("----------------------------");
                            }
                            else {
                                printf("\n올바른 값을 입력하세요\n");
                                select1=0;
                                goto game2;
                            }
                        }
                        else if (select1==0) {
                            srand((unsigned int)time(NULL));
                            ran=rand()%9+1;
                            if(choi[ran]=='o'||choi[ran]=='x') {
                                while(choi[ran]=='o'||choi[ran]=='x') {
                                    srand((unsigned int)time(NULL));
                                    ran=rand()%9+1;
                                }
                                choi[ran]='o';
                            }
                            else {
                                choi[ran]='o';
                            }
                            select1=0;
                            final();
                            board();
                            goto game2;
                        }
                        else {
                            start=0;
                            printf("\n올바른 값을 입력하세요\n");
                            diff=0;
                            goto game1;
                        }
                    }
                }
            }
            else if(start==2) {                                                                                               //게임 설명
Easter_port :
                start=0;
                printf("\n-------------------------------\n");
                printf("     a   b   c  ");
                printf("\n  ┌───┬───┬───┐");
                printf("\n1 │(1)│(2)│(3)│");
                printf("\n  ├───┼───┼───┤");
                printf("\n2 │(4)│(5)│(6)│");
                printf("\n  ├───┼───┼───┤");
                printf("\n3 │(7)│(8)│(9)│");
                printf("\n  └───┴───┴───┘");
Tuto1 :
                printf("\n\na열 1행은 1번이고 c열 3행은 9번 입니다.\n칸 번호를 입력하여 칸을 선택하세요\n\n");
                scanf("%d", &select1);
                if(select1>=1&&select1<=9) {
                    srand((unsigned int)time(NULL));                                                                          //이스터애그
                    if(rand()%20<=18) {
                        choi[select1]='o';
                    }
                    else {
                        choi[select1]='z';
                    }
                    printf("\n--------------------------------------");
                    board();
Tuto2 :
                    printf("\n\n선택하면 그에 맞는 칸에 o를 쓸 수 있습니다. (다음 설명 : 1)\n");
                    scanf("%d", &start);
                }
                else if(select1==123456789) {
                    i=1;
                    while(i<=9) {
                        choi[i]='o';
                        i+=1;
                    }
                    i=0;
                    printf("\n--------------------------------------");
                    board();
                    printf("\n규칙을 무시한 당신, 당신이 이겼습니다...\n");                                                   //이스터애그3
                    exit(0);

                }
                else {
                    printf("\n올바른 값을 입력하세요\n");
                    goto Tuto1;
                    select1=0;
                }
                if(start==1) {
                    if(select1==1||select1==4||select1==7) {
                        choi[select1+1]='x';
                    }
                    else if(select1==2||select1==5||select1==8) {
                        choi[select1+1]='x';
                    }
                    else if(select1==3||select1==6||select1==9) {
                        choi[select1-1]='x';
                    }
                    start=0;
                    printf("\n-----------------------------------------------------------");
                    board();
Tuto3 :
                    printf("\n\no가 선택하면 다음에 x가 선택합니다. (다음 설명 : 1)\n");
                    scanf("%d", &start);
                }
                else {
                    printf("\n올바른 값을 입력하세요\n");
                    start=0;
                    goto Tuto2;
                }

                if(start==1) {
                    if(select1>=1&&select1<=3) {
                        choi[select1+3]='o';
                        choi[select1+6]='o';
                    }
                    else if(select1>=4&&select1<=6) {
                        choi[select1+3]='o';
                        choi[select1-3]='o';
                    }
                    else if(select1>=7&&select1<=9) {
                        choi[select1-3]='o';
                        choi[select1-6]='o';
                    }
                }
                else {
                    printf("\n올바른 값을 입력하세요\n");
                    goto Tuto3;
                    start=0;
                }
                if(select1==1||select1==4||select1==7) {
                    choi[select1+2]='x';
                }
                else if(select1==2||select1==5||select1==8) {
                    choi[select1-1]='x';
                }
                else if(select1==3||select1==6||select1==9) {
                    choi[select1-2]='x';
                }
                printf("\n--------------------------------------------------");
                board();
                if(choi[select1]=='o') {
                    printf("\n\nx의 선택을 고려하여 1줄을 연결시키면 당신의 승리입니다\n(게임 설명 나가기 : 아무 숫자)\n-------------------------------------------------------\n");
                }
                else if(choi[select1]=='z') {
                    printf("\n\n튜토리얼도 못 깼군요.  당신의 패배입니다\n(게임 설명 나가기 : 아무 숫자)\n-----------------------------------------\n");
                }                                                                                                                 //이스터애그2
                select1=0;
                scanf("%d", &start);
                i=1;
                while(i<=9) {
                    choi[i]=' ';
                    i+=1;
                }
                if(start>=0||start<0) {
                    start=0;
                    goto Start;
                }
            }
            else {                                                                                                            //선택 외
                printf("\n올바른 값을 입력하세요\n");
                goto Start;
            }
        }
        else {
Easter_start :
            printf("\n     메뉴\n--------------\n(게임 설명 : 1)\n") ;                                                       //이스터애그1
            scanf("%d", &start);
            if(start==1) {
                start=0;
                goto Easter_port;
            }
            else {
                start=0;
                goto Easter_start;
            }

        }
    }
    else {                                                                                                                //시작 외
        printf("\n올바른 값을 입력하세요\n");
        goto First;
    }

}
// 메인 끝



int f_tictacto() {                                                                                                        // 선공
    if(diff==1) {
        printf("\n----------------\n  게임 : 하급\n----------------\nO가 선공 입니다\n");
    }
    else if(diff==2) {
        printf("\n----------------\n  게임 : 상급\n----------------\nO가 선공 입니다\n");
    }
    board();
    select1=0;
    while(1) {
game :  
    if(str_era<7){
        printf("\n칸을 선택하세요 (무작위 선택 : 0)\n---------------------------------\n");
    }
    else{
    	printf("\n칸을 선택하세요 (무작위 선택 : 0) (수상한 지우개 : 10)\n------------------------------------------------------\n");
	}
        scanf("%d",&select1);
        if(select1<=9&&select1>=1) {
            if(choi[select1]!='o'&&choi[select1]!='x') {
                choi[select1]='o';
                select1=0;
                final();
                tic_ai();
                final();
                board();
                printf("\nX가 선택했습니다\n----------------\n");
            }
            else {
                choi_exc+=1;
                if(choi_exc<=9) {
                    printf("\n올바른 값을 입력하세요\n");
                    select1=0;
                    goto game;
                }
                else if(choi_exc==10) {
                    if(diff==1) {
                        printf("\n이걸 원하시는 건가요?\n");                                                                      //이스터애그4
                        choi_exc=0;
                        choi[select1]='o';
                        select1=0;
                        final();
                        tic_ai();
                        final();
                        board();
                        printf("\n---------------------\n화난 X가 선택했습니다\n\n");
                    }
                    else {
                        printf("\여기서는 통하지 않습니다. 다시 선택하세요.\n");                                                                      //이스터애그4
                        choi_exc=0;
                        select1=0;
                        goto game;
                    }
                }


            }
        }
        else if (select1==0) {
            srand((unsigned int)time(NULL));
            ran=rand()%9+1;
            if(choi[ran]=='o'||choi[ran]=='x') {
                while(choi[ran]=='o'||choi[ran]=='x') {
                    srand((unsigned int)time(NULL));
                    ran=rand()%9+1;
                }
                choi[ran]='o';
            }
            else {
                choi[ran]='o';
            }
            final();
            tic_ai();
            final();
            board();
            printf("\nX가 선택했습니다\n----------------\n");
            select1=0;
        }
        else if(select1==10){
        	if(str_era>=7){
        		srand((unsigned int)time(NULL));
            ran=rand()%9+1;
            if(choi[ran]=='o'||choi[ran]=='x') {
                choi[ran]=' ';
            }
            else {
            	while(choi[ran]!='o'&&choi[ran]!='x') {
                    srand((unsigned int)time(NULL));
                    ran=rand()%9+1;
                }
                choi[ran]=' ';
            }
        		select1=0;
        		 str_era=0; 
        printf("\n%d칸을 지웠습니다.\n수상한 지우개를 사용했더니 지우개똥이 나왔다. (지우개똥 +1)\n------------------------------------------------------------\n",ran);
        tic_ai();
                final();
                board();
                printf("\nX가 선택했습니다\n----------------\n");
    }
    }
        else {
            printf("\n올바른 값을 입력하세요\n");
            select1=0;
            goto game;
        }
    }
}

int s_tictacto() {                                                                                                        //후공
    if(diff==1) {
        printf("\n----------------\n  게임 : 하급\n----------------\nO가 후공 입니다\n");
    }
    else if(diff==2) {
        printf("\n----------------\n  게임 : 상급\n----------------\nO가 후공 입니다\n");
    }
    while(1) {
        printf("\nX가 선택했습니다\n\n");
        tic_ai();
        final();
        board();
game :
        if(str_era<7){
        printf("\n칸을 선택하세요 (무작위 선택 : 0)\n---------------------------------\n");
    }
    else{
    	printf("\n칸을 선택하세요 (무작위 선택 : 0) (수상한 지우개 : 10)\n-----------------------------------------------------------------\n");
	}
        scanf("%d",&select1);
        if(select1<=9&&select1>=1) {
            if(choi[select1]!='o'&&choi[select1]!='x') {
                choi[select1]='o';
                select1=0;
                final();
            }
            else {
                choi_exc+=1;
                if(choi_exc<=9) {
                    printf("\n올바른 값을 입력하세요\n");
                    select1=0;
                    goto game;
                }
                else if(choi_exc==10) {
                    if(diff==1) {
                        printf("\n이걸 원하시는 건가요?\n");                                                                      //이스터애그4
                        choi_exc=0;
                        choi[select1]='o';
                        final();
                        tic_ai();
                        final();
                        board();
                        printf("\n-------------------\n화난 X가 선택했습니다\n\n");
                        select1=0;
                    }
                    else {
                        printf("\여기서는 통하지 않습니다. 다시 선택하세요.\n");                                                                      //이스터애그4
                        choi_exc=0;
                        select1=0;
                        goto game;
                    }


                }
            }
        }
        else if(select1==102) {
            printf("\nForced_Progress : Inter/S_Game/Device >> Inter/B_Game/Device\n------------------------------------------------------------\n\n");
            select1=0;                                                                                                    //이스터애그5
            i=1;
            while(i<=9) {
                choi[i]=' ';
                i+=1;
            }
            i=0;
            f_tictacto();
            return 0;
        }
        else if (select1==0) {
            srand((unsigned int)time(NULL));
            ran=rand()%9+1;
            if(choi[ran]=='o'||choi[ran]=='x') {
                while(choi[ran]=='o'||choi[ran]=='x') {
                    srand((unsigned int)time(NULL));
                    ran=rand()%9+1;
                }
                choi[ran]='o';
            }
            else {
                choi[ran]='o';
            }
            select1=0;
            final();
            board();
        }
        else if(select1==10){
        	if(str_era>=7){
        		srand((unsigned int)time(NULL));
            ran=rand()%9+1;
            if(choi[ran]=='o'||choi[ran]=='x') {
                choi[ran]=' ';
            }
            else {
            	while(choi[ran]!='o'&&choi[ran]!='x') {
                    srand((unsigned int)time(NULL));
                    ran=rand()%9+1;
                }
                choi[ran]=' ';
            }
        		select1=0;
        		 str_era=0; 
        printf("\n%d칸을 지웠습니다.\n수상한 지우개를 사용했더니 지우개똥이 나왔다. (지우개똥 +1)\n------------------------------------------------------------\n",ran);
    }
    }
        else {
            printf("\n올바른 값을 입력하세요\n");
            select1=0;
            goto game;
        }
    }
}



int board(void) {                                                                                                         //틱텍토보드
    printf("\n    a   b   c  ");
    printf("\n  ┌───┬───┬───┐");
    printf("\n1 │ %c │ %c │ %c │",choi[1],choi[2],choi[3]);
    printf("\n  ├───┼───┼───┤");
    printf("\n2 │ %c │ %c │ %c │",choi[4],choi[5],choi[6]);
    printf("\n  ├───┼───┼───┤");
    printf("\n3 │ %c │ %c │ %c │",choi[7],choi[8],choi[9]);
    printf("\n  └───┴───┴───┘");
    return 0;
}



int tic_select(void) {                                                                                                    //틱텍토 선공 선택 값
    start=0;
    select1=0;
    srand((unsigned int)time(NULL));
    if(rand()%2==0) {
        s_tictacto();
        select1=0;
        return 0;
    }
    else {
        f_tictacto();
        select1=0;
        return 0;
    }
    return 0;
}




int tic_ai(void) {                                                                                                        //선택 AI
    if(diff==1) {
        srand((unsigned int)time(NULL));
        ran=rand()%9+1;
        if(choi[ran]=='o'||choi[ran]=='x') {
            while(choi[ran]=='o'||choi[ran]=='x') {
                srand((unsigned int)time(NULL));
                ran=rand()%9+1;
            }
            choi[ran]='x';
            return 0;
        }
        else {
            choi[ran]='x';
            return 0;
        }
    }
    else if(diff==2) {

        if(choi[5]!='x'&&choi[5]!='o') {
            srand((unsigned int)time(NULL));
            if(rand()%100<=79) {
                choi[5]='x';
                return 0;
            }
            else {
                srand((unsigned int)time(NULL));
                ran=rand()%9+1;
                if(choi[ran]=='o'||choi[ran]=='x') {
                    while(choi[ran]=='o'||choi[ran]=='x') {
                        srand((unsigned int)time(NULL));
                        ran=rand()%9+1;
                    }
                    choi[ran]='x';
                    return 0;
                }
                else {
                    choi[ran]='x';
                    return 0;
                }
            }
        }
        i=1;
        while(i<=7) {
            if(choi[i]=='x'&&choi[1+i]=='x') {
                if(choi[i+2]!='x'&&choi[i+2]!='o') {
                    choi[i+2]='x';
                    return 0;
                }
                i+=3;
            }
            else if(choi[i]=='x'&&choi[2+i]=='x') {
                if(choi[i+1]!='x'&&choi[i+1]!='o') {
                    choi[i+1]='x';
                    return 0;
                }
                i+=3;
            }
            else if(choi[2+i]=='x'&&choi[1+i]=='x') {
                if(choi[i]!='x'&&choi[i]!='o') {
                    choi[i]='x';
                    return 0;
                }
                i+=3;
            }
            else
            i+=3;
            }
        
        i=1;
        while(i<=3) {
            if(choi[i]=='x'&&choi[3+i]=='x') {
                if(choi[i+6]!='x'&&choi[i+6]!='o') {
                    choi[i+6]='x';
                    return 0;
                }
                i+=1;
            }
            else if(choi[i]=='x'&&choi[6+i]=='x') {
                if(choi[i+3]!='x'&&choi[i+3]!='o') {
                    choi[i+3]='x';
                    return 0;
                }
                i+=1;
            }
            else if(choi[6+i]=='x'&&choi[3+i]=='x') {
                if(choi[i]!='x'&&choi[i]!='o') {
                    choi[i]='x';
                    return 0;
                }
                i+=1;
            }
            else
            i+=1;
        }
        i=1;
        while(i<=7){
        if(choi[i]=='o'&&choi[1+i]=='o') {
                if(choi[i+2]!='x'&&choi[i+2]!='o') {
                    choi[i+2]='x';
                    return 0;
                }
                i+=3;
            }
        else if(choi[i]=='o'&&choi[2+i]=='o') {
                if(choi[i+1]!='x'&&choi[i+1]!='o') {
                    choi[i+1]='x';
                    return 0;
                }
                i+=3;
            }
        else if(choi[2+i]=='o'&&choi[1+i]=='o') {
                if(choi[i]!='x'&&choi[i]!='o') {
                    choi[i]='x';
                    return 0;
                }
                i+=3;
            }
           else
           i+=3;
        }
        i=1;
        while(i<=3){
        if(choi[i]=='o'&&choi[3+i]=='o') {
                if(choi[i+6]!='x'&&choi[i+6]!='o') {
                    choi[i+6]='x';
                    return 0;
                }
                i+=1;
            }
        else if(choi[i]=='o'&&choi[6+i]=='o') {
                if(choi[i+3]!='x'&&choi[i+3]!='o') {
                    choi[i+3]='x';
                    return 0;
                }
                i+=1;
            }
        else if(choi[6+i]=='o'&&choi[3+i]=='o') {
                if(choi[i]!='x'&&choi[i]!='o') {
                    choi[i]='x';
                    return 0;
                }
                i+=1;
            }
           else
           i+=1;
        }

        if(choi[1]=='x'&&choi[5]=='x') {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
        else if(choi[1]=='o'&&choi[5]=='o') {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
        if(choi[9]=='x'&&choi[5]=='x') {
            if(choi[1]!='x'&&choi[1]!='o') {
                choi[1]='x';
                return 0;
            }
        }
        else if(choi[9]=='o'&&choi[5]=='o') {
            if(choi[1]!='x'&&choi[1]!='o') {
                choi[1]='x';
                return 0;
            }
        }
        if(choi[1]=='x'&&choi[9]=='x') {
            if(choi[5]!='x'&&choi[5]!='o') {
                choi[5]='x';
                return 0;
            }
        }
        else if(choi[1]=='o'&&choi[9]=='o') {
            if(choi[5]!='x'&&choi[5]!='o') {
                choi[5]='x';
                return 0;
            }
        }

        if(choi[3]=='x'&&choi[5]=='x') {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }
        }
        else if(choi[3]=='o'&&choi[5]=='o') {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }
        }
        if(choi[7]=='x'&&choi[5]=='x') {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        else if(choi[7]=='o'&&choi[5]=='o') {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        if(choi[3]=='x'&&choi[7]=='x') {
            if(choi[5]!='x'&&choi[5]!='o') {
                choi[5]='x';
                return 0;
            }
        }
        else if(choi[3]=='o'&&choi[7]=='o') {
            if(choi[5]!='x'&&choi[5]!='o') {
                choi[5]='x';
                return 0;
            }
        }

        if(choi[2]=='x'&&choi[7]=='x') {
            if(choi[1]!='x'&&choi[1]!='o') {
                choi[1]='x';
                return 0;
            }
        }
        else if(choi[2]=='o'&&choi[7]=='o') {
            if(choi[1]!='x'&&choi[1]!='o') {
                choi[1]='x';
                return 0;
            }
        }
        if(choi[2]=='x'&&choi[9]=='x') {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        else if(choi[2]=='o'&&choi[9]=='o') {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        if(choi[6]=='x'&&choi[1]=='x') {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        else if(choi[6]=='o'&&choi[1]=='o') {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        if(choi[6]=='x'&&choi[7]=='x') {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
        else if(choi[6]=='o'&&choi[7]=='o') {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
        if(choi[8]=='x'&&choi[3]=='x') {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
        else if(choi[8]=='o'&&choi[3]=='o') {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
        if(choi[8]=='x'&&choi[1]=='x') {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }
        }
        else if(choi[8]=='o'&&choi[1]=='o') {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }
        }
        if(choi[4]=='x'&&choi[3]=='x') {
            if(choi[1]!='x'&&choi[1]!='o') {
                choi[1]='x';
                return 0;
            }
        }
        else if(choi[4]=='o'&&choi[3]=='o') {
            if(choi[1]!='x'&&choi[1]!='o') {
                choi[1]='x';
                return 0;
            }
        }
        if(choi[4]=='x'&&choi[9]=='x') {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }
        }
        else if(choi[4]=='o'&&choi[9]=='o') {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }
        }

        if(choi[5]=='o') {
            srand((unsigned int)time(NULL));
            if(rand()%4==0) {
                if(choi[1]!='x'&&choi[1]!='o') {
                    choi[1]='x';
                    return 0;
                }
            }
        }
        else if(rand()%4==1) {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        else if(rand()%4==2) {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }
        }
        else {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
    }

    if(choi[5]=='o'||choi[5]=='x') {
        if(choi[1]=='o'||choi[1]=='x') {
            if(choi[9]=='o'||choi[9]=='o') {
                if(choi[3]!='x'&&choi[3]!='o') {
                    choi[3]='x';
                    return 0;
                }
            }
        }
        if(choi[9]=='o'||choi[9]=='x') {
            if(choi[1]=='o'||choi[1]=='o') {
                if(choi[7]!='x'&&choi[7]!='o') {
                    choi[7]='x';
                    return 0;
                }

            }
        }
        if(choi[7]=='o'||choi[7]=='x') {
            if(choi[3]=='o'||choi[3]=='o') {
                if(choi[1]!='x'&&choi[1]!='o') {
                    choi[1]='x';
                    return 0;
                }

            }
        }
        if(choi[3]=='o'||choi[3]=='x') {
            if(choi[7]=='o'||choi[7]=='o') {
                if(choi[9]!='x'&&choi[9]!='o') {
                    choi[9]='x';
                    return 0;
                }

            }
        }

    }
    
    if(choi[5]=='o'||choi[5]=='x') {
        if(choi[1]=='o'||choi[1]=='x') {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
        if(choi[9]=='o'||choi[9]=='x') {
            if(choi[1]!='x'&&choi[1]!='o') {
                choi[1]='x';
                return 0;
            }
        }
        if(choi[7]=='o'||choi[7]=='x') {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        if(choi[3]=='o'||choi[3]=='x') {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }

        }
    }




    if(choi[5]=='o'||choi[5]=='x') {
        srand((unsigned int)time(NULL));
        if(rand()%4==0) {
            if(choi[1]!='x'&&choi[1]!='o') {
                choi[1]='x';
                return 0;
            }
        }
        else if(rand()%4==1) {
            if(choi[3]!='x'&&choi[3]!='o') {
                choi[3]='x';
                return 0;
            }
        }
        else if(rand()%4==2) {
            if(choi[7]!='x'&&choi[7]!='o') {
                choi[7]='x';
                return 0;
            }
        }
        else {
            if(choi[9]!='x'&&choi[9]!='o') {
                choi[9]='x';
                return 0;
            }
        }
    }
    
        srand((unsigned int)time(NULL));
    ran=rand()%9+1;
    if(choi[ran]=='o'||choi[ran]=='x') {
        while(choi[ran]=='o'||choi[ran]=='x') {
            srand((unsigned int)time(NULL));
            ran=rand()%9+1;
        }
        choi[ran]='x';
        return 0;
    }
    else {
        choi[ran]='x';
        return 0;
    }

}






int finale() {                                                                                                           //판정
    if(choi[i]=='O') {
        printf("\n--------------\nO의 승리입니다");
        exit(0);
    }
    else if(choi[i]=='X') {
        printf("\n--------------\nX의 승리입니다");
        exit(0);
    }
    return 0;
}


int final() {                                                                                                             //승리 감지
    i=1;
    while(i<=7) {
        if(choi[i]==choi[i+1]&&choi[i+1]==choi[i+2]) {
            if(choi[i]=='o'||choi[i]=='x') {
                if(choi[i]=='o') {
                    choi[i]='O';
                    choi[i+1]='O';
                    choi[i+2]='O';
                }
                else if(choi[i]=='x') {
                    choi[i]='X';
                    choi[i+1]='X';
                    choi[i+2]='X';
                }
                board();
                finale();
            }
        }
        i+=3;
    }
    i=1;
    while(i<=3) {
        if(choi[i]==choi[i+3]&&choi[i+3]==choi[i+6]) {
            if(choi[i]=='o'||choi[i]=='x') {
                if(choi[i]=='o') {
                    choi[i]='O';
                    choi[i+3]='O';
                    choi[i+6]='O';
                }
                else if(choi[i]=='x') {
                    choi[i]='X';
                    choi[i+3]='X';
                    choi[i+6]='X';
                }
                board();
                finale();
            }
        }
        i+=1;
    }
    i=1;
    if(choi[i]==choi[i+4]&&choi[i+4]==choi[i+8]) {
        if(choi[i]=='o'||choi[i]=='x') {
            if(choi[i]=='o') {
                choi[i]='O';
                choi[i+4]='O';
                choi[i+8]='O';
            }
            else if(choi[i]=='x') {
                choi[i]='X';
                choi[i+4]='X';
                choi[i+8]='X';
            }
            board();
            finale();
        }
    }
    i=3;
    if(choi[i]==choi[i+2]&&choi[i+2]==choi[i+4]) {
        if(choi[i]=='o'||choi[i]=='x') {
            if(choi[i]=='o') {
                choi[i]='O';
                choi[i+2]='O';
                choi[i+4]='O';
            }
            else if(choi[i]=='x') {
                choi[i]='X';
                choi[i+2]='X';
                choi[i+4]='X';
            }
            board();
            finale();
        }
    }
    i=1;
    while(i<=9) {
        if(choi[i]=='o'||choi[i]=='x') {
            i+=1;
            if(i>=10) {
                board();
                printf("\n-------------\n무승부 입니다");
                exit(0);
            }
        }
        else {
            return 0;
        }
    }
    return 0;
}

