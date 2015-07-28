// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "gecode/search/message.pb.hh"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace message {

namespace {

const ::google::protobuf::Descriptor* Node_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Node_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Node_MsgType_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* Node_NodeStatus_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_message_2eproto() {
  protobuf_AddDesc_message_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "message.proto");
  GOOGLE_CHECK(file != NULL);
  Node_descriptor_ = file->message_type(0);
  static const int Node_offsets_[14] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, sid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, pid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, alt_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, kids_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, restart_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, thread_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, label_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, domain_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, solution_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, nogood_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, info_),
  };
  Node_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Node_descriptor_,
      Node::default_instance_,
      Node_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Node));
  Node_MsgType_descriptor_ = Node_descriptor_->enum_type(0);
  Node_NodeStatus_descriptor_ = Node_descriptor_->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_message_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Node_descriptor_, &Node::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_message_2eproto() {
  delete Node::default_instance_;
  delete Node_reflection_;
}

void protobuf_AddDesc_message_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rmessage.proto\022\007message\"\261\003\n\004Node\022#\n\004typ"
    "e\030\001 \002(\0162\025.message.Node.MsgType\022\013\n\003sid\030\002 "
    "\001(\005\022\013\n\003pid\030\003 \001(\005\022\013\n\003alt\030\004 \001(\005\022\014\n\004kids\030\005 "
    "\001(\005\022(\n\006status\030\006 \001(\0162\030.message.Node.NodeS"
    "tatus\022\022\n\nrestart_id\030\007 \001(\005\022\014\n\004time\030\010 \001(\004\022"
    "\021\n\tthread_id\030\t \001(\005\022\r\n\005label\030\n \001(\t\022\023\n\013dom"
    "ain_size\030\013 \001(\002\022\020\n\010solution\030\014 \001(\t\022\016\n\006nogo"
    "od\030\r \001(\t\022\014\n\004info\030\016 \001(\t\"(\n\007MsgType\022\010\n\004NOD"
    "E\020\000\022\010\n\004DONE\020\001\022\t\n\005START\020\002\"r\n\nNodeStatus\022\n"
    "\n\006SOLVED\020\000\022\n\n\006FAILED\020\001\022\n\n\006BRANCH\020\002\022\020\n\014UN"
    "DETERMINED\020\003\022\010\n\004STOP\020\004\022\n\n\006UNSTOP\020\005\022\013\n\007SK"
    "IPPED\020\006\022\013\n\007MERGING\020\007", 460);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "message.proto", &protobuf_RegisterTypes);
  Node::default_instance_ = new Node();
  Node::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_message_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_message_2eproto {
  StaticDescriptorInitializer_message_2eproto() {
    protobuf_AddDesc_message_2eproto();
  }
} static_descriptor_initializer_message_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* Node_MsgType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Node_MsgType_descriptor_;
}
bool Node_MsgType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Node_MsgType Node::NODE;
const Node_MsgType Node::DONE;
const Node_MsgType Node::START;
const Node_MsgType Node::MsgType_MIN;
const Node_MsgType Node::MsgType_MAX;
const int Node::MsgType_ARRAYSIZE;
#endif  // _MSC_VER
const ::google::protobuf::EnumDescriptor* Node_NodeStatus_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Node_NodeStatus_descriptor_;
}
bool Node_NodeStatus_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Node_NodeStatus Node::SOLVED;
const Node_NodeStatus Node::FAILED;
const Node_NodeStatus Node::BRANCH;
const Node_NodeStatus Node::UNDETERMINED;
const Node_NodeStatus Node::STOP;
const Node_NodeStatus Node::UNSTOP;
const Node_NodeStatus Node::SKIPPED;
const Node_NodeStatus Node::MERGING;
const Node_NodeStatus Node::NodeStatus_MIN;
const Node_NodeStatus Node::NodeStatus_MAX;
const int Node::NodeStatus_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int Node::kTypeFieldNumber;
const int Node::kSidFieldNumber;
const int Node::kPidFieldNumber;
const int Node::kAltFieldNumber;
const int Node::kKidsFieldNumber;
const int Node::kStatusFieldNumber;
const int Node::kRestartIdFieldNumber;
const int Node::kTimeFieldNumber;
const int Node::kThreadIdFieldNumber;
const int Node::kLabelFieldNumber;
const int Node::kDomainSizeFieldNumber;
const int Node::kSolutionFieldNumber;
const int Node::kNogoodFieldNumber;
const int Node::kInfoFieldNumber;
#endif  // !_MSC_VER

Node::Node()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:message.Node)
}

void Node::InitAsDefaultInstance() {
}

Node::Node(const Node& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:message.Node)
}

void Node::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = 0;
  sid_ = 0;
  pid_ = 0;
  alt_ = 0;
  kids_ = 0;
  status_ = 0;
  restart_id_ = 0;
  time_ = GOOGLE_ULONGLONG(0);
  thread_id_ = 0;
  label_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  domain_size_ = 0;
  solution_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  nogood_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  info_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Node::~Node() {
  // @@protoc_insertion_point(destructor:message.Node)
  SharedDtor();
}

void Node::SharedDtor() {
  if (label_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete label_;
  }
  if (solution_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete solution_;
  }
  if (nogood_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete nogood_;
  }
  if (info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete info_;
  }
  if (this != default_instance_) {
  }
}

void Node::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Node::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Node_descriptor_;
}

const Node& Node::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_message_2eproto();
  return *default_instance_;
}

Node* Node::default_instance_ = NULL;

Node* Node::New() const {
  return new Node;
}

void Node::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Node*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(type_, restart_id_);
  }
  if (_has_bits_[8 / 32] & 16128) {
    thread_id_ = 0;
    if (has_label()) {
      if (label_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        label_->clear();
      }
    }
    domain_size_ = 0;
    if (has_solution()) {
      if (solution_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        solution_->clear();
      }
    }
    if (has_nogood()) {
      if (nogood_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        nogood_->clear();
      }
    }
    if (has_info()) {
      if (info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        info_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Node::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:message.Node)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .message.Node.MsgType type = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::message::Node_MsgType_IsValid(value)) {
            set_type(static_cast< ::message::Node_MsgType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_sid;
        break;
      }

      // optional int32 sid = 2;
      case 2: {
        if (tag == 16) {
         parse_sid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &sid_)));
          set_has_sid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_pid;
        break;
      }

      // optional int32 pid = 3;
      case 3: {
        if (tag == 24) {
         parse_pid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &pid_)));
          set_has_pid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_alt;
        break;
      }

      // optional int32 alt = 4;
      case 4: {
        if (tag == 32) {
         parse_alt:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &alt_)));
          set_has_alt();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_kids;
        break;
      }

      // optional int32 kids = 5;
      case 5: {
        if (tag == 40) {
         parse_kids:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &kids_)));
          set_has_kids();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_status;
        break;
      }

      // optional .message.Node.NodeStatus status = 6;
      case 6: {
        if (tag == 48) {
         parse_status:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::message::Node_NodeStatus_IsValid(value)) {
            set_status(static_cast< ::message::Node_NodeStatus >(value));
          } else {
            mutable_unknown_fields()->AddVarint(6, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_restart_id;
        break;
      }

      // optional int32 restart_id = 7;
      case 7: {
        if (tag == 56) {
         parse_restart_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &restart_id_)));
          set_has_restart_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_time;
        break;
      }

      // optional uint64 time = 8;
      case 8: {
        if (tag == 64) {
         parse_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &time_)));
          set_has_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_thread_id;
        break;
      }

      // optional int32 thread_id = 9;
      case 9: {
        if (tag == 72) {
         parse_thread_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &thread_id_)));
          set_has_thread_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_label;
        break;
      }

      // optional string label = 10;
      case 10: {
        if (tag == 82) {
         parse_label:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_label()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->label().data(), this->label().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "label");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(93)) goto parse_domain_size;
        break;
      }

      // optional float domain_size = 11;
      case 11: {
        if (tag == 93) {
         parse_domain_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &domain_size_)));
          set_has_domain_size();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_solution;
        break;
      }

      // optional string solution = 12;
      case 12: {
        if (tag == 98) {
         parse_solution:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_solution()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->solution().data(), this->solution().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "solution");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_nogood;
        break;
      }

      // optional string nogood = 13;
      case 13: {
        if (tag == 106) {
         parse_nogood:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nogood()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->nogood().data(), this->nogood().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "nogood");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(114)) goto parse_info;
        break;
      }

      // optional string info = 14;
      case 14: {
        if (tag == 114) {
         parse_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_info()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->info().data(), this->info().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "info");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:message.Node)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:message.Node)
  return false;
#undef DO_
}

void Node::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:message.Node)
  // required .message.Node.MsgType type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // optional int32 sid = 2;
  if (has_sid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->sid(), output);
  }

  // optional int32 pid = 3;
  if (has_pid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->pid(), output);
  }

  // optional int32 alt = 4;
  if (has_alt()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->alt(), output);
  }

  // optional int32 kids = 5;
  if (has_kids()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->kids(), output);
  }

  // optional .message.Node.NodeStatus status = 6;
  if (has_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      6, this->status(), output);
  }

  // optional int32 restart_id = 7;
  if (has_restart_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->restart_id(), output);
  }

  // optional uint64 time = 8;
  if (has_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(8, this->time(), output);
  }

  // optional int32 thread_id = 9;
  if (has_thread_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(9, this->thread_id(), output);
  }

  // optional string label = 10;
  if (has_label()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->label().data(), this->label().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "label");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      10, this->label(), output);
  }

  // optional float domain_size = 11;
  if (has_domain_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(11, this->domain_size(), output);
  }

  // optional string solution = 12;
  if (has_solution()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->solution().data(), this->solution().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "solution");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      12, this->solution(), output);
  }

  // optional string nogood = 13;
  if (has_nogood()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nogood().data(), this->nogood().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nogood");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      13, this->nogood(), output);
  }

  // optional string info = 14;
  if (has_info()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->info().data(), this->info().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "info");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      14, this->info(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:message.Node)
}

::google::protobuf::uint8* Node::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:message.Node)
  // required .message.Node.MsgType type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // optional int32 sid = 2;
  if (has_sid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->sid(), target);
  }

  // optional int32 pid = 3;
  if (has_pid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->pid(), target);
  }

  // optional int32 alt = 4;
  if (has_alt()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->alt(), target);
  }

  // optional int32 kids = 5;
  if (has_kids()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->kids(), target);
  }

  // optional .message.Node.NodeStatus status = 6;
  if (has_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      6, this->status(), target);
  }

  // optional int32 restart_id = 7;
  if (has_restart_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->restart_id(), target);
  }

  // optional uint64 time = 8;
  if (has_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(8, this->time(), target);
  }

  // optional int32 thread_id = 9;
  if (has_thread_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, this->thread_id(), target);
  }

  // optional string label = 10;
  if (has_label()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->label().data(), this->label().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "label");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        10, this->label(), target);
  }

  // optional float domain_size = 11;
  if (has_domain_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(11, this->domain_size(), target);
  }

  // optional string solution = 12;
  if (has_solution()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->solution().data(), this->solution().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "solution");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        12, this->solution(), target);
  }

  // optional string nogood = 13;
  if (has_nogood()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nogood().data(), this->nogood().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nogood");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        13, this->nogood(), target);
  }

  // optional string info = 14;
  if (has_info()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->info().data(), this->info().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "info");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        14, this->info(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:message.Node)
  return target;
}

int Node::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .message.Node.MsgType type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

    // optional int32 sid = 2;
    if (has_sid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->sid());
    }

    // optional int32 pid = 3;
    if (has_pid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->pid());
    }

    // optional int32 alt = 4;
    if (has_alt()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->alt());
    }

    // optional int32 kids = 5;
    if (has_kids()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->kids());
    }

    // optional .message.Node.NodeStatus status = 6;
    if (has_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->status());
    }

    // optional int32 restart_id = 7;
    if (has_restart_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->restart_id());
    }

    // optional uint64 time = 8;
    if (has_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->time());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional int32 thread_id = 9;
    if (has_thread_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->thread_id());
    }

    // optional string label = 10;
    if (has_label()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->label());
    }

    // optional float domain_size = 11;
    if (has_domain_size()) {
      total_size += 1 + 4;
    }

    // optional string solution = 12;
    if (has_solution()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->solution());
    }

    // optional string nogood = 13;
    if (has_nogood()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->nogood());
    }

    // optional string info = 14;
    if (has_info()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->info());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Node::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Node* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Node*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Node::MergeFrom(const Node& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_sid()) {
      set_sid(from.sid());
    }
    if (from.has_pid()) {
      set_pid(from.pid());
    }
    if (from.has_alt()) {
      set_alt(from.alt());
    }
    if (from.has_kids()) {
      set_kids(from.kids());
    }
    if (from.has_status()) {
      set_status(from.status());
    }
    if (from.has_restart_id()) {
      set_restart_id(from.restart_id());
    }
    if (from.has_time()) {
      set_time(from.time());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_thread_id()) {
      set_thread_id(from.thread_id());
    }
    if (from.has_label()) {
      set_label(from.label());
    }
    if (from.has_domain_size()) {
      set_domain_size(from.domain_size());
    }
    if (from.has_solution()) {
      set_solution(from.solution());
    }
    if (from.has_nogood()) {
      set_nogood(from.nogood());
    }
    if (from.has_info()) {
      set_info(from.info());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Node::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Node::CopyFrom(const Node& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Node::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void Node::Swap(Node* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(sid_, other->sid_);
    std::swap(pid_, other->pid_);
    std::swap(alt_, other->alt_);
    std::swap(kids_, other->kids_);
    std::swap(status_, other->status_);
    std::swap(restart_id_, other->restart_id_);
    std::swap(time_, other->time_);
    std::swap(thread_id_, other->thread_id_);
    std::swap(label_, other->label_);
    std::swap(domain_size_, other->domain_size_);
    std::swap(solution_, other->solution_);
    std::swap(nogood_, other->nogood_);
    std::swap(info_, other->info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Node::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Node_descriptor_;
  metadata.reflection = Node_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace message

// @@protoc_insertion_point(global_scope)
