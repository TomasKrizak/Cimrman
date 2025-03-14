// TK headers
#include "tkrec/Precluster.h"

// Standard library:
#include <limits> // infinity
#include <cmath> // isnan

#include <datatools/exception.h>

// ClassImp(tkrec::Precluster);

namespace tkrec {

  Precluster::Precluster(const std::vector<ConstTrackerHitHdl> & tracker_hits, bool _prompt, int _side)
    : Precluster()
  {
    DT_THROW_IF(tracker_hits.size() < 1, std::logic_error, "No tracker hits");
    for(auto & tracker_hit : tracker_hits)
    {
      unclustered_tracker_hits.push_back(tracker_hit);    
    }
    prompt = _prompt;
    side = _side;
    return;
  }

  std::vector<ConstTrackerHitHdl> & Precluster::get_unclustered_tracker_hits()
  {
    return unclustered_tracker_hits;
  }

  const std::vector<ConstTrackerHitHdl> & Precluster::get_unclustered_tracker_hits() const
  {
    return unclustered_tracker_hits;
  }

  std::vector<ClusterHdl> & Precluster::get_clusters()
  {
    return linear_clusters;
  }

  std::vector<ConstClusterHdl> Precluster::get_clusters() const
  {
    std::vector<ConstClusterHdl> clusters;
    for (const auto & cluster : linear_clusters) {
      clusters.push_back(cluster);
    }
    return clusters;
  }
  
  std::vector<PreclusterSolutionHdl> & Precluster::get_precluster_solutions()
  {
  	return precluster_solutions;
  }
  
  std::vector<ConstPreclusterSolutionHdl> Precluster::get_precluster_solutions() const
  {
    std::vector<ConstPreclusterSolutionHdl> solutions;
    for (const auto & solution : precluster_solutions) 
    {
      solutions.push_back(solution);
    }
    return solutions;
  }

  bool Precluster::is_prompt() const
  {
    return prompt;
  }
  
  int Precluster::get_side() const
  {
    return side;
  }

  void Precluster::print(std::ostream & out_) const
  {
    out_ << "Precluster | clusters: " << linear_clusters.size()
         << ", unclustered tracker hits: " << unclustered_tracker_hits.size() << std::endl;
  }

} //  end of namespace tkrec
