#ifndef PRIMITIVE_VISUAL_H
#define PRIMITIVE_VISUAL_H

#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreVector3.h>
#include <kr_planning_msgs/PrimitiveArray.h>
#include <kr_planning_rviz_plugins/data_type.h>
#include <rviz/ogre_helpers/billboard_line.h>

namespace kr_planning_rviz_plugins {
class PrimitiveVisual {
 public:
  PrimitiveVisual(Ogre::SceneManager* scene_manager,
                  Ogre::SceneNode* parent_node);

  virtual ~PrimitiveVisual();

  void setMessage(const std::vector<kr_planning_msgs::Primitive>& msgs);

  void setFramePosition(const Ogre::Vector3& position);
  void setFrameOrientation(const Ogre::Quaternion& orientation);

  void setNum(int n);
  void setYawNum(int n);
  void setPosColor(float r, float g, float b, float a);
  void setVelColor(float r, float g, float b, float a);
  void setAccColor(float r, float g, float b, float a);
  void setJrkColor(float r, float g, float b, float a);
  void setYawColor(float r, float g, float b, float a);
  void setPosScale(float s);
  void setVelScale(float s);
  void setAccScale(float s);
  void setJrkScale(float s);
  void setYawScale(float s);
  void setYawTriangleScale(float s);
  void setYawTriangleAngle(float a);
  void setVelVis(bool vis);
  void setAccVis(bool vis);
  void setJrkVis(bool vis);
  void setYawVis(bool vis);

 private:
  std::vector<std::unique_ptr<rviz::BillboardLine>> poss_;
  std::vector<std::unique_ptr<rviz::BillboardLine>> vels_;
  std::vector<std::unique_ptr<rviz::BillboardLine>> accs_;
  std::vector<std::unique_ptr<rviz::BillboardLine>> jrks_;
  std::vector<std::unique_ptr<rviz::BillboardLine>> yaws_;

  Ogre::SceneNode* frame_node_;
  Ogre::SceneManager* scene_manager_;

  int num_;
  int yaw_num_;
  double dyaw_{M_PI / 6};
  double syaw_{0.25};
  bool vel_vis_;
  bool acc_vis_;
  bool jrk_vis_;
  bool yaw_vis_;
};
}  // namespace kr_planning_rviz_plugins

#endif
