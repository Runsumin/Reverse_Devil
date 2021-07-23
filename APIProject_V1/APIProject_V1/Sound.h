#ifndef _SOUND_H
#define _SOUND_H
#include <windows.h>
//Windows MultiMedia ���̺귯��
#pragma comment(lib,"winmm")
//Windows MultiMedia DigitalVideo Command set ���
#include <Digitalv.h>


/*
���� ���
wav,mp3 ���� Ȯ���ڸ� �����մϴ�.
sound�� soundPlayLoopingWav�Լ��� ������ ��� sound�� �Լ�����
�⺻������ �ѹ��� ȣ��Ǿ���մϴ�.
*/

//���� ������ ������ ����ü
//����ü�� ���� ���� �����ϸ� �ȵ˴ϴ�.
typedef struct _SoundInfo
{
	UINT DeviceID;
	BOOL isPause;
}SoundInfo;

//���� ������ ���ϴ�.
//������ ��� TRUE�� �����մϴ�.
BOOL soundOpen(SoundInfo* sound, LPSTR FileName);
//���� ������ �ݽ��ϴ�. 
//������ ��� TRUE�� �����մϴ�.
BOOL soundClose(SoundInfo* sound);
//�����ִ� ��� ���� ������ �ݽ��ϴ�.
//������ ��� TRUE�� �����մϴ�.
BOOL soundCloseAll();
//���带 ����մϴ�.
//���� ����� �����ϸ� FALSE�� �����մϴ�.
BOOL soundPlay(SoundInfo* sound);
//���带 �ݺ�����մϴ�.(wav������ �ݺ����� �ʰ� �ѹ��� ����մϴ�.) 
//���� ����� �����ϸ� FALSE�� �����մϴ�.
BOOL soundPlayLooping(SoundInfo* sound);
//���� ����� �Ͻ������մϴ�.
//���尡 ������� �ƴѰ�� FALSE�� �����մϴ�.
BOOL soundPause(SoundInfo* sound);
//���� ����� �簳�մϴ�.
//���尡 ������� ��� FALSE�� �����մϴ�.
BOOL soundResume(SoundInfo* sound);
//������ ������ �����ɴϴ�.
//�����Ұ�� ������ �����ϰ� �����ϸ� -1�� ��ȯ�մϴ�.
DWORD soundGetVolume(SoundInfo* sound);
//������ ������ �����մϴ�. ������ 0 ~ 1000 ������ ���� ���� �� �ֽ��ϴ�.
//���������� ������ ��� TRUE�� �����մϴ�.
BOOL soundSetVolume(SoundInfo* sound, DWORD volume);
//������� ���带 ������ ��ġ���� ����ϵ��� �̵���Ű�� �Լ�
//ȣ���� ����� ���߱⶧���� �̵��� �ٽ� play�Լ��� ȣ���ؾ��մϴ�.
BOOL soundSeek(SoundInfo* sound, DWORD seekTo);
//wav������ �ݺ�����ϵ��� �ϴ� �Լ�
//�� �Լ��� MCI������ �߻��������� FALSE�� �����ϰ� �׻� TRUE�� ��ȯ�մϴ�.
//���ӷ��� �ȿ��� ��� ȣ���ϸ� ��� �ݺ������ �ϰ�,
//�ѹ��� ȣ���ϸ� ���尡 ��� ����Ǿ����� ó������ �ٽ� ����մϴ�.
BOOL soundPlayLoopingWav(SoundInfo* sound);

#endif // !_SOUND_H