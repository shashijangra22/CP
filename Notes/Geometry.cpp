// closest pair of points in a 2D plane (NLogN) Sweep line algorithm
double closestPair(vector<pii> &points){
	int n = points.size();
    sort(all(points));	// sorted by x co-ordinate
    set<pii> box;	// sorted by y co-ordinate 

	int j=0;
	loop(i,0,n-1,1){
		int d=ceil(best);

		while( abs(points[i].first - points[j].first) >= best){
			box.erase({points[j].second,points[j].first});	// removing point if farther than best
			j++;
		}
 
		auto low = box.lb({points[i].second - d, points[i].first});	// lower limit of box
		auto high = box.ub({points[i].second + d, points[i].first}); // upper limit of box

		while(low!=high){
			int dx = points[i].first - low->second;
			int dy = points[i].second - low->first;
			best=min(best,sqrt(dx*dx + dy*dy));		// updating min distance
			low++;
		}
		box.insert({points[i].second,points[i].first});	// adding new point
	}
	return best;	// min distance
}