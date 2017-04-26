#include<functional>

namespace minfill::graphs {
	class Edge {
			int from, to;
		public:
			Edge(int f, int t) {
				from = f;
				to = t;
			}
			int getFrom() const { return from; }
			int getTo() const { return to; }
	};
}

namespace std
{
    template<>
	struct hash<minfill::graphs::Edge> {
		size_t operator()(const minfill::graphs::Edge & x) const {
    	    if (x.getFrom() < x.getTo()) {
				return 31*x.getFrom()+x.getTo();
			}
			return 31*x.getTo()+x.getFrom();
		}
    };
    template<>
	struct equal_to<minfill::graphs::Edge> {
		bool operator()(const minfill::graphs::Edge& x, const minfill::graphs::Edge& y) const {
			return (x.getFrom() == y.getFrom() && x.getTo() == y.getTo()) ||
				   (x.getFrom() == y.getTo() && x.getTo() == y.getFrom());
		}
	};
}