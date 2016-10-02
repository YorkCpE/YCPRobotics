// Generated by gencpp from file map_merger/TransformPointResponse.msg
// DO NOT EDIT!


#ifndef MAP_MERGER_MESSAGE_TRANSFORMPOINTRESPONSE_H
#define MAP_MERGER_MESSAGE_TRANSFORMPOINTRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <adhoc_communication/MmPoint.h>

namespace map_merger
{
template <class ContainerAllocator>
struct TransformPointResponse_
{
  typedef TransformPointResponse_<ContainerAllocator> Type;

  TransformPointResponse_()
    : point()  {
    }
  TransformPointResponse_(const ContainerAllocator& _alloc)
    : point(_alloc)  {
  (void)_alloc;
    }



   typedef  ::adhoc_communication::MmPoint_<ContainerAllocator>  _point_type;
  _point_type point;




  typedef boost::shared_ptr< ::map_merger::TransformPointResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::map_merger::TransformPointResponse_<ContainerAllocator> const> ConstPtr;

}; // struct TransformPointResponse_

typedef ::map_merger::TransformPointResponse_<std::allocator<void> > TransformPointResponse;

typedef boost::shared_ptr< ::map_merger::TransformPointResponse > TransformPointResponsePtr;
typedef boost::shared_ptr< ::map_merger::TransformPointResponse const> TransformPointResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::map_merger::TransformPointResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::map_merger::TransformPointResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace map_merger

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'adhoc_communication': ['/home/carasperbeck/ros_ws/src/robot_navigation/aau_multi_robot-master/adhoc_communication/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::map_merger::TransformPointResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::map_merger::TransformPointResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::map_merger::TransformPointResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::map_merger::TransformPointResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::map_merger::TransformPointResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::map_merger::TransformPointResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::map_merger::TransformPointResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ff0adb045fabd1e2f01bd484ef29c081";
  }

  static const char* value(const ::map_merger::TransformPointResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xff0adb045fabd1e2ULL;
  static const uint64_t static_value2 = 0xf01bd484ef29c081ULL;
};

template<class ContainerAllocator>
struct DataType< ::map_merger::TransformPointResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "map_merger/TransformPointResponse";
  }

  static const char* value(const ::map_merger::TransformPointResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::map_merger::TransformPointResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "adhoc_communication/MmPoint point\n\
\n\
\n\
================================================================================\n\
MSG: adhoc_communication/MmPoint\n\
string src_robot\n\
float64 x\n\
float64 y\n\
";
  }

  static const char* value(const ::map_merger::TransformPointResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::map_merger::TransformPointResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.point);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TransformPointResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::map_merger::TransformPointResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::map_merger::TransformPointResponse_<ContainerAllocator>& v)
  {
    s << indent << "point: ";
    s << std::endl;
    Printer< ::adhoc_communication::MmPoint_<ContainerAllocator> >::stream(s, indent + "  ", v.point);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAP_MERGER_MESSAGE_TRANSFORMPOINTRESPONSE_H
