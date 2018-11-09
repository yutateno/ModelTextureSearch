#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


int main()
{
	// ---------------------------------------------------------------------
	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0)
	{
		// エラーが発生したら直ちに終了
		return -1;
	}

	ChangeWindowMode(true);


	// ---------------------------------------------------------------------
	int modelHandle = MV1LoadModel("media\\CLPH_\\CLPH.mv1");

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
			saveFile << i << "," << MV1GetTextureColorFilePath(modelHandle, i) << "\n";
		}
	}

	// ファイルを閉じる
	saveFile.close();


	// ---------------------------------------------------------------------
	// int MV1SetTextureColorFilePath( int MHandle, int TexIndex, const TCHAR *FilePath ) ;// カラーテクスチャのファイルパスを変更する
	// これ使って変更すればいい

	return 0;
}