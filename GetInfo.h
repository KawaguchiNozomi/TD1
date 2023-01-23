#pragma once
class GetInfo
{
public:
	static int GetBlockSize() { return blockSize_; }
	static int GetMapHeigth() { return mapHeight_; }
	static int GetMapWidth() { return mapWidth_; }
	static int GetWindowWidth() { return windowWidth_; }
	static int GetWindowHeight() { return windowHeight_; }

private:
	static const int blockSize_ = 64;
	static const int mapHeight_ = 11;
	static const int mapWidth_ = 30;
	static const int windowWidth_ = 1000;
	static const int windowHeight_=720;
};