#ifndef ID_MANAGER_H
#define ID_MANAGER_H


class IDManager {
public:
    int get_new_id() {
        next_id_++;
        return next_id_ - 1;
    };

private:
int next_id_ = 0; 
};

#endif // ID_MANAGER_H