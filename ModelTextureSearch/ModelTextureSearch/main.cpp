#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "DxLib.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	if (__argc == 1)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "exeにpmd/mqo/pmx/mqx/mv1をドラッグアンドドロップしてください。\n何かキーを押してください。");

		WaitKey();

		return -1;
	}


	// ---------------------------------------------------------------------
	int modelHandle = MV1LoadModel(__argv[1]);

	const int textureNum = MV1GetTextureNum(modelHandle);


	// ---------------------------------------------------------------------
	std::ofstream saveFile;
	saveFile.open("Save.csv");		// ファイルオープン

	// ファイル読み込み失敗
	if (saveFile.fail())
	{
		printf("SaveError\n");
	}
	else
	{
		// 読み込み成功
		saveFile << "ID" << "," << "名前" << "\n";
		for (int i = 0; i < textureNum; i++)
		{
			saveFile << i << "," << MV1GetTextureColorFilePath(modelHandle, i) << std::endl;
		}
	}

	// ファイルを閉じる
	saveFile.close();

	DrawFormatString(0, 0, GetColor(255,255,255), "ファイル読み込み及びcsv書き出し終了しました\n何かキーを押してください。");

	WaitKey();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}