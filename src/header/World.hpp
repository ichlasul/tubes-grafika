class World {
public:
	World();
	~World();


private:
	Background bg;
	Car car;
	ObstaclesList obs;
	ScoreBoard sb;
	int isRunning;
	int timer;
	int lastUpdateTime;
	int fps;
};