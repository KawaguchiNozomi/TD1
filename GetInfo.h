#pragma once
/// <summary>
/// 色々な数値 大きさなどの定数
/// </summary>
class GetInfo
{
public:
	/// <summary>
	/// マップチップのでかさ
	/// </summary>
	/// <returns></returns>
	static int GetBlockSize() { return blockSize_; }
	/// <summary>
	/// マップの高さ
	/// </summary>
	/// <returns></returns>
	static int GetMapHeigth() { return mapHeight_; }
	/// <summary>
	/// マップの長さ
	/// </summary>
	/// <returns></returns>
	static int GetMapWidth() { return mapWidth_; }
	/// <summary>
	/// ウィンドウサイズの横幅
	/// </summary>
	/// <returns></returns>
	static int GetWindowWidth() { return windowWidth_; }
	/// <summary>
	/// ウィンドウサイズの縦幅
	/// </summary>
	/// <returns></returns>
	static int GetWindowHeight() { return windowHeight_; }
	/// <summary>
	/// プレイヤーのスプライトサイズ
	/// </summary>
	/// <returns></returns>
	static int GetPlayerSpriteSize() { return playerSpriteSize_; }
	/// <summary>
	/// プレイヤーのスプライト半径
	/// </summary>
	/// <returns></returns>
	static int GetPlayerSpriteRadius() { return playerSpriteRadius_; }
	/// <summary>
	/// 初期高度
	/// </summary>
	/// <returns></returns>
	static int GetBaseLevel() { return baseLevel_; }

private:
	static const int blockSize_ = 64;
	static const int playerSpriteSize_ = 64;
	static const int playerSpriteRadius_ = playerSpriteSize_ / 2;
	static const int mapHeight_ = 11;
	static const int mapWidth_ = 30;
	static const int windowWidth_ = 1000;
	static const int windowHeight_=720;
	static const int baseLevel_ = blockSize_ * 8;
};