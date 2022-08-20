#include<bits/stdc++.h>

#define N 25
#define K 3

using namespace std;

struct Point {
    double x;
    double y;
    Point() {
        x = 0;
        y = 0;
    }
};

struct Mean {
    Point all;
    int n;
    Mean() {
        all.x = 0;
        all.y = 0;
        n = 0;
    }
    void add(Point& p) {
        all.x += p.x;
        all.y += p.y;
        n++;
    }
    void remov(Point& p) {
        all.x -= p.x;
        all.y -= p.y;
        n--;
    }
    Point centre() {
        Point c;
        c.x = all.x / n;
        c.y = all.y / n;
        return c;
    }
};


double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int find_near(Point p, vector<Mean>& c) {
    int idx = -1;
    double md = 10000;
    for (int i = 0;i < c.size();i++) {
        double cd = distance(p, c[i].centre());
        if (cd < md) {
            md = cd;
            idx = i;
        }
    }
    return idx;
}
vector<vector<Point>> kMeans(vector<Point>& points, int nc) {
    vector<vector<Point>> clusters(nc);
    vector<Mean> c(nc, Mean());
    for (int i = 0;i < nc;i++) {
        clusters[i].push_back(points[i]);
        c[i].add(points[i]);
    }
    for (int i = nc;i < points.size();i++) {
        int idx = find_near(points[i], c);
        clusters[idx].push_back(points[i]);
        c[idx].add(points[i]);
    }
    int changed = 1;
    while (changed > 0) {
        changed = 0;
        for (int i = 0;i < nc;i++) {
            vector<Point> currCluster(clusters[i]);
            for (int j = 0;j < currCluster.size();j++) {
                int idx = find_near(currCluster[j], c);
                if (idx == i) continue;
                changed++;
                auto itr = clusters[i].begin();
                for (;itr != clusters[i].end(); itr++) {
                    if (itr->x == currCluster[j].x && itr->y == currCluster[j].y)break;
                }
                clusters[i].erase(itr);
                c[i].remov(currCluster[j]);
                clusters[idx].push_back(currCluster[j]);
                c[idx].add(currCluster[j]);
            }
        }
    }
    return clusters;
}

int main() {
    srand(time(NULL));
    ofstream out("output.txt");
    vector<Point> points;
    for (int i = 0; i < N; i++) {
        Point p;
        p.x = rand() % 100;
        p.y = rand() % 100;
        points.push_back(p);
    }
    vector<vector<Point>> clusters;
    clusters = kMeans(points, K);
    for (int i = 0;i < clusters.size();i++) {
        out << "Cluster " << i << ":\n";
        for (int j = 0;j < clusters[i].size(); j++) {
            out << clusters[i][j].x << " " << clusters[i][j].y << endl;
        }
        out << endl;
    }
}
