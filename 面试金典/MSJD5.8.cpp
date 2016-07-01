class Render {
public:
	vector<int> renderPixel(vector<int> screen, int x, int y) {
		int val[8] = {1,2,4,8,16,32,64,128};
		for (int i = 0; i < screen.size(); ++i)
		{
			int left = i*8;
			int right = left+7;
			if (left>=x&&right<=y)
			{
				screen[i] = 255;
			}
			else if (right<x||left>y)
			{
				continue;
			}
			else if (left<=x&&right<=y)
			{
				int count = 0;
				for (int i = x; i <= right; ++i)
				{
					count += val[i%8];
				}
				screen[i] |= count;
			}
			else if (left>=x&&right>=y)
			{
				int count = 0;
				for (int i = left; i <= y; ++i)
				{
					count += val[i%8];
				}
				screen[i] |= count;
			}
		}
		return screen;
	}
};