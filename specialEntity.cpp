class Special_Entity {
    public:
        int start_position;
        int end_position;
        Special_Entity(int start, int end) {
            start_position = start;
            end_position = end;
        }
};

class Snake : public Special_Entity {
    public:
        Snake(int start, int end) : Special_Entity(start, end) {}
};

class Ladder : public Special_Entity {
    public:
        Ladder(int start, int end) : Special_Entity(start, end) {}
};