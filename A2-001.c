#include <stdio.h>

int count = 1;   // นับจุดเริ่มต้นก่อน   

typedef struct SEGMENT{
    int left_edge;
    int right_edge;
    int direction;
}S;

int checkLeftEdge(int left_edge_1, int left_edge_2){
    return left_edge_1 > left_edge_2?left_edge_1:left_edge_2;
}

int checkRightEdge(int right_edge_1, int right_edge_2){
    return right_edge_1 < right_edge_2?right_edge_1:right_edge_2;
}

void createSegments(int arr[], int size, S blank[], int *segment_size){
    *segment_size = 0;
    for (int i=0;i<size-1;++i){
        blank[*segment_size].left_edge = arr[i];
        blank[*segment_size].right_edge = arr[i+1];
        blank[*segment_size].direction = i % 2;
        ++(*segment_size);
    }
}

void process(int red[], int blue[], int red_size, int blue_size){
    S red_segments[red_size-1];
    S blue_segments[blue_size-1];
    int red_segment_size;
    int blue_segment_size;
    createSegments(red, red_size, red_segments, &red_segment_size);
    createSegments(blue, blue_size, blue_segments, &blue_segment_size);
    //printf("red_segment_size: %d\n", red_segment_size);
    //printf("blue_segment_size: %d\n", blue_segment_size);
    int red_index = 0;
    int blue_index = 0;
    while ((red_index < red_segment_size) && (blue_index < blue_segment_size)){
        int red_left_edge = red_segments[red_index].left_edge;
        int red_right_edge = red_segments[red_index].right_edge;
        int red_direction = red_segments[red_index].direction;

        int blue_left_edge = blue_segments[blue_index].left_edge;
        int blue_right_edge = blue_segments[blue_index].right_edge;
        int blue_direction = blue_segments[blue_index].direction;

        int left_edge_overlap;
        int right_edge_overlap;
        //
        //printf("Before: (%d,%d,%d) (%d,%d,%d)\n", red_left_edge, red_right_edge, red_direction, blue_left_edge, blue_right_edge, blue_direction);
        //
        left_edge_overlap = checkLeftEdge(red_left_edge, blue_left_edge);
        right_edge_overlap = checkRightEdge(red_right_edge, blue_right_edge);
        if ((left_edge_overlap < right_edge_overlap) && (red_direction != blue_direction)){
            ++count;
            //
            //printf("(%d,%d,%d) (%d,%d,%d)\n", red_left_edge, red_right_edge, red_direction, blue_left_edge, blue_right_edge, blue_direction);
            //
        }
        if ((red_right_edge == blue_right_edge) && (red_direction == blue_direction)){
            ++count;
            ++red_index;
            ++blue_index;
             //
             //printf("(%d,%d,%d) (%d,%d,%d)\n", red_left_edge, red_right_edge, red_direction, blue_left_edge, blue_right_edge, blue_direction);
             //
        }else {
            if (red_right_edge < blue_right_edge){
                ++red_index;
            }else {
                ++blue_index;
            }
        }
    }
}

int main(){
    int N, M;
    if ((scanf("%d %d", &N, &M) == 2)){
        int red[N+1];
        red[0] = 0;
        for (int i=1;i<N+1;++i){
            if ((scanf("%d", &red[i]) != 1)){
                break;
            }
        }
        //
        //for (int i=0;i<N+1;++i){
        //    printf("%d ", red[i]);
        //}printf("\n");
        //
        int blue[M+1];
        blue[0] = 0;
        for (int i=1;i<M+1;++i){
            if (scanf("%d", &blue[i]) != 1){
                break;
            }
        }
        //
        //for (int i=0;i<M+1;++i){
        //    printf("%d ", blue[i]);
        //}printf("\n");
        //
        process(red, blue, N+1, M+1);
    }
    printf("%d\n", count);
    return 0;
}
