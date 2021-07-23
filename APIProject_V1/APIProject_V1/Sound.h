#ifndef _SOUND_H
#define _SOUND_H
#include <windows.h>
//Windows MultiMedia 라이브러리
#pragma comment(lib,"winmm")
//Windows MultiMedia DigitalVideo Command set 헤더
#include <Digitalv.h>


/*
사운드 모듈
wav,mp3 등의 확장자를 지원합니다.
sound의 soundPlayLoopingWav함수를 제외한 모든 sound의 함수들은
기본적으로 한번만 호출되어야합니다.
*/

//사운드 정보를 저장할 구조체
//구조체의 값을 직접 변경하면 안됩니다.
typedef struct _SoundInfo
{
	UINT DeviceID;
	BOOL isPause;
}SoundInfo;

//사운드 파일을 엽니다.
//성공할 경우 TRUE를 리턴합니다.
BOOL soundOpen(SoundInfo* sound, LPSTR FileName);
//사운드 파일을 닫습니다. 
//성공할 경우 TRUE를 리턴합니다.
BOOL soundClose(SoundInfo* sound);
//열려있는 모든 사운드 파일을 닫습니다.
//성공할 경우 TRUE를 리턴합니다.
BOOL soundCloseAll();
//사운드를 재생합니다.
//사운드 재생을 실패하면 FALSE를 리턴합니다.
BOOL soundPlay(SoundInfo* sound);
//사운드를 반복재생합니다.(wav파일은 반복되지 않고 한번만 재생합니다.) 
//사운드 재생을 실패하면 FALSE를 리턴합니다.
BOOL soundPlayLooping(SoundInfo* sound);
//사운드 재생을 일시정지합니다.
//사운드가 재생중이 아닌경우 FALSE를 리턴합니다.
BOOL soundPause(SoundInfo* sound);
//사운드 재생을 재개합니다.
//사운드가 재생중일 경우 FALSE를 리턴합니다.
BOOL soundResume(SoundInfo* sound);
//사운드의 볼륨을 가져옵니다.
//성공할경우 볼륨을 리턴하고 실패하면 -1을 반환합니다.
DWORD soundGetVolume(SoundInfo* sound);
//사운드의 볼륨을 설정합니다. 볼륨은 0 ~ 1000 사이의 값을 가질 수 있습니다.
//볼륨설정에 성공한 경우 TRUE를 리턴합니다.
BOOL soundSetVolume(SoundInfo* sound, DWORD volume);
//재생중인 사운드를 지정한 위치부터 재생하도록 이동시키는 함수
//호출후 재생이 멈추기때문에 이동후 다시 play함수를 호출해야합니다.
BOOL soundSeek(SoundInfo* sound, DWORD seekTo);
//wav파일을 반복재생하도록 하는 함수
//이 함수는 MCI오류가 발생했을때만 FALSE를 리턴하고 항상 TRUE를 반환합니다.
//게임루프 안에서 계속 호출하면 계속 반복재생을 하고,
//한번만 호출하면 사운드가 모두 재생되었을때 처음부터 다시 재생합니다.
BOOL soundPlayLoopingWav(SoundInfo* sound);

#endif // !_SOUND_H