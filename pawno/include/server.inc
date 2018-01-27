#define SERVER_FILE "user/serverconfig"
#pragma tabsize 0
main()
{
    	new file[256];
	format(file, sizeof(file),SERVER_FILE);
	if(!dini_Exists(file))
	{
		printf("-------------에러-------------");
		printf("당신은 불법적으로 이 모드를 사용하였습니다");
		printf(" 서버가 종료됩니다 ");
		SendRconCommand("exit");
	}
	else if(fexist(file))
	{
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print(" ");
		print("======================= New Ethiopia Role Playing Mode ===================");
		print(" ");
		print(" ");
		print("               Mode Maker : MatDongSan([J.F]Marry(dasfdasfsa))            ");
		print(" ");
		print(" ");
		print("==========================================================================");
		print(" ");
		print(" ");
	}
}