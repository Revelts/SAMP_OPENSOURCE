#include a_samp.inc
#include dini.inc
#include dudb.inc
#include streamer.inc
#include utils.inc
#include a_npc.inc
#include gameinfo.inc
#include veh.inc
#include audio.inc


#define M_P 	200
#define Anim(%1) ApplyAnimation(%1,1)

#define Func:%0(%1) \
		forward %0(%1);\
		public %0(%1)

#define PLAYER_CAMERA_HEIGHT 20.0
#define CAMERA_ZOOM_VALUE 40.0 //카메라 고도상승 범위.
#define DEFAULT_CAMERA_ZOOM 120.0 //카메라 기본고도
#define CAMERA_MOVE_DISTANCE 5.0 //카메라 이동범위.
#define MISSILE_SPEED 50.0

#define callback:%0(%1) forward %0(%1); public %0(%1) // 콜백함수 간편하게 정의해주는 매크로.

#define MAX_SHOOT_DISTANCE 15.0
#define speedcolor 0x008080FF

enum pInfo
{
	Key[128],			    // 비번
	pAdmin,                             // 어드민
        pGMNick[256],                       // GM닉네임
        pOldGMNick[256],                    // 백업된 GM닉 (즉 바꾸기전 닉)
	pLevel,                             // 레벨
	pExp,                               // 경험치
	pSex,                               // 성별
	pAge,                               // 나이
	pSkin,                              // 스킨
	pTut,                               // 튜토리얼
	pPlayerSave,			    // 저장
    	pLeader,                            // 리더
	pMember,                            // 나라
	pRank,                              // 계급
	pCash,                              // 돈
	pCay,                               // 병과
	pAban,                              // 아이디밴
	pSquad[2],			    // 분대
	pJail,                              // 드모르간
	pJailTime,                          // 드모르간 시간
	pKos,                               // 경고
	pCos,				    // 칭찬
	pGoodjob,                           // 훈장
	pBadjob,			    // 징계
	pPayDay,                            // 월급봉투
	pMoneyTime,			    // 월급시간
	pBbox,                              // 붐박스
	pDice,                              // 주사위
	pCigar,                             // 담배
	pCia,				    // 술
	pCias,				    // 술(취함/안취함)
	pCiac,				    // 해소제
	pHemostatic,                        // 모르핀
	pCamera,                            // 카메라
	pAyg,                               // 계산기
	pRadio,                             // 사설무전기
	pWatch,                             // 시계
	pClean,                             // 악취
	pHungry,                            // 배고픔
	pNotes[5],                          // 메모
	pNote1[128],                        // 메모[1]
	pNote2[128],                        // 메모[2]
	pNote3[128],                        // 메모[3]
	pNote4[128],                        // 메모[4]
	pNote5[128],                        // 메모[5]
	gExp[2],                            // 계급 경험치
	pBomb,				    // 폭격
	Float:pBombPos,			    // 폭격위치
	Float:pBoomPos[3],                  // 폭격위치
	pLeaderCool,			    // 폭격 대기시간
	pFrequency,			    // 무전 주파수
	pNationalmoney,			    // 기부한 금액
	pHops,				    // 확성기
	pCuffed,			    // 군용철사
	pBombCf,			    // 신호탄
	pPlayerChoco,			    // 취사병
	pPlayerDie,			    // 기절
	pPlayerDeath,			    // 죽음
	pDieTime,			    // 혼수상태 시간
	pChoco[2],                          // 음식
	pChoco1[128],                       // 음식[1]
	pChoco2[128]                        // 음식[2]
	pAdminCheck			   //어드민체크
}
new PlayerInfo[MAX_PLAYERS][pInfo];

new CaptureTimers[M_P][6];

new ArmyGate1[3]; 			  // [0] = 매복산 [1] = 재점령 대기 시간
new ArmyGate2[3]; 			  // [0] = 캉 마을 [1] = 재점령 대기 시간
new ArmyGate3[3]; 			  // [0] = 별장 [1] = 재점령 대기 시간
new ArmyGate4[3]; 			  // [0] = 유적지 [1] = 재점령 대기 시간
new ArmyGate5[3]; 			  // [0] = 언덕 [1] = 재점령 대기 시간
new ArmyGate6[3];			  // [0] = 미국 전초기지 [1] = 재점령 대기 시간
new ArmyGate7[3];                         // [0] = 금문교 [1] = 재점령 대기 시간
new ArmyGate8[3];                         // [0] = 항공모함 [1] = 재점령 대기 시간

new ArmyGate1Text[128];
new ArmyGate2Text[128];
new ArmyGate3Text[128];
new ArmyGate4Text[128];
new ArmyGate5Text[128];
new ArmyGate6Text[128];
new ArmyGate7Text[128];
new ArmyGate8Text[128];

new Kangmaeul;
new Maeboksan;
new Sightseeing;
new Villa;
new Hill;
new USAHQ;
new GOLDBRIGE;
new AIRBASE;
new RUSTeamGang;
new USATeamGang;