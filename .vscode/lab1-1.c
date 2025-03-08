/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){ 
// 이 곳에 생각 정리와 코드 구현
// person이 값을 저장하니까 조금은 다르게 생각할 필요가 있다.
// person[0] : 2
// person[1] : 2
// person[2] : 2
// person[3] : 2
// person[4] : 2
// 이런식으로 생각하는게 맞는듯 한데
// 그니까 내가 줄 수 있는 같은 person 일때 2 이상 못주게 하면 되는거지 그리고
// 호실은 person 0 1 2 3 4 일 때 +1 만 해서 내주면 되는데
// 이 거를 랜덤으로 썪어서 할 수 있는 방법을 찾으면 될듯
// 먼저 랜덤으로 방을 찾고 그 값이 2가 안되면 값을 배정? 어떰?
// 만약에 2가 차있으면 다른 방 찾으면 되는 거잖아.. 이거다 진짜	
	int randNum; 
	while(1){
	randNum = (rand() % 5) +1;

	if(persons[randNum]<2){
		persons[randNum]++;
		break;
		}
	}

	return randNum;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// 이 곳에 생각 정리와 코드 구현
	printf("남학생 명단 (%d명)",mc);
	printf("\n");
	for(int i=0; i<mc; i++){
		printf("%d. %s [%d호]",i+1,mn[i],mr[i]);
		printf("\n");
	}
	printf("\n");
	printf("여학생 명단 (%d명)",wc);
	printf("\n");
	for(int i=0; i<wc; i++){
		printf("%d. %s [%d호]",i+1,wn[i],wr[i]);
		printf("\n");
	}
	printf("\n");
	//-------------------------------------------
	
	printf("호실별 배정 명단");
	printf("\n");
		
	for(int i=0; i<10; i++){
		if(i<5) {
			//mn 이랑 mr 은 순서가 똑같잖아
			//그러면 일단 mr 이 일치하는 순간의 i 를 출력하면 될거야.
			printf("10%d호 : ",i+1);
			for(int k=0;k<10;k++){
				if(mr[k]==101+i){
					printf("%s " , mn[k]);
				}
				else{
					printf("");
				}
			}
			printf("\n");
		}
		else{
			printf("20%d호 : ",i-4);
			for(int k=0;k<10;k++){
				if(wr[k]==201+i-5){
					printf("%s " , wn[k]);
				}
				else{
					printf("");
				}
			}
			printf("\n");
		}
	}


}
