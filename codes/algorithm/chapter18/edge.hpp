#ifndef EDGE_HPP
#define EDGE_HPP
class Edge{
    private:
        int n1, n2, distance;
    public:
        Edge(const int n1, const int n2, const int distance){
            this->n1 = n1;
            this->n2 = n2;
            this->distance = distance;
        }
        int getN1() const{
            return n1;
        }
        int getN2() const{
            return n2;
        }
        int getDistance() const{
            return distance;
        }
        bool operator <(const Edge edge) const{
            return this->distance < edge.getDistance();
        }
};
#endif // EDGE_HPP