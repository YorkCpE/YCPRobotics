// Generated by gencpp from file adhoc_communication/MmControl.msg
// DO NOT EDIT!


#ifndef ADHOC_COMMUNICATION_MESSAGE_MMCONTROL_H
#define ADHOC_COMMUNICATION_MESSAGE_MMCONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace adhoc_communication
{
template <class ContainerAllocator>
struct MmControl_
{
  typedef MmControl_<ContainerAllocator> Type;

  MmControl_()
    : src_robot()
    , update_numbers()  {
    }
  MmControl_(const ContainerAllocator& _alloc)
    : src_robot(_alloc)
    , update_numbers(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _src_robot_type;
  _src_robot_type src_robot;

   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _update_numbers_type;
  _update_numbers_type update_numbers;




  typedef boost::shared_ptr< ::adhoc_communication::MmControl_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::adhoc_communication::MmControl_<ContainerAllocator> const> ConstPtr;

}; // struct MmControl_

typedef ::adhoc_communication::MmControl_<std::allocator<void> > MmControl;

typedef boost::shared_ptr< ::adhoc_communication::MmControl > MmControlPtr;
typedef boost::shared_ptr< ::adhoc_communication::MmControl const> MmControlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::adhoc_communication::MmControl_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::adhoc_communication::MmControl_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace adhoc_communication

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'adhoc_communication': ['/home/carasperbeck/ros_ws/src/robot_navigation/aau_multi_robot-master/adhoc_communication/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::adhoc_communication::MmControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::adhoc_communication::MmControl_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::adhoc_communication::MmControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::adhoc_communication::MmControl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::adhoc_communication::MmControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::adhoc_communication::MmControl_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::adhoc_communication::MmControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3d223057e1839a50fdaaef262568a5a7";
  }

  static const char* value(const ::adhoc_communication::MmControl_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3d223057e1839a50ULL;
  static const uint64_t static_value2 = 0xfdaaef262568a5a7ULL;
};

template<class ContainerAllocator>
struct DataType< ::adhoc_communication::MmControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "adhoc_communication/MmControl";
  }

  static const char* value(const ::adhoc_communication::MmControl_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::adhoc_communication::MmControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string src_robot\n\
int32[] update_numbers\n\
";
  }

  static const char* value(const ::adhoc_communication::MmControl_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::adhoc_communication::MmControl_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.src_robot);
      stream.next(m.update_numbers);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MmControl_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::adhoc_communication::MmControl_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::adhoc_communication::MmControl_<ContainerAllocator>& v)
  {
    s << indent << "src_robot: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.src_robot);
    s << indent << "update_numbers[]" << std::endl;
    for (size_t i = 0; i < v.update_numbers.size(); ++i)
    {
      s << indent << "  update_numbers[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.update_numbers[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ADHOC_COMMUNICATION_MESSAGE_MMCONTROL_H