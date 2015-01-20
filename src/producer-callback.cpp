/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014 Regents of the University of California.
 *
 * @author Lijing Wang <phdloli@ucla.edu>
 */

#include "producer-callback.hpp"
#include <boost/asio.hpp>

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespace could be used to prevent/limit name contentiojs
  
  ProducerCallback::ProducerCallback()
  : m_interestCounter(0)
  {
  }
  
  void
  ProducerCallback::setProducer(Producer* p)
  {
    m_producer = p;
  }
  
  void
  ProducerCallback::setSampleNumber(size_t* n)
  {
//    m_curnum = n;
  }
  
  void
  ProducerCallback::processConstData(const Data& data){}
  
  /* When the request can't be satisfied from the content store */
  void
  ProducerCallback::processInterest(const Interest& interest)
  {
    //if (interet.getName().get(-2).toSegment() < m_crrnFrameNumer)
   /*
    m_interestCounter++;
  
    if (m_interestCounter == 1)
    {
      ApplicationNack appNack(interest, ApplicationNack::PRODUCER_DELAY);
      appNack.setDelay(5000); // in ms
      m_producer->nack(appNack);
    }
    else if (m_interestCounter == 2)
    {
      CPUTemp cputemp; 
      cputemp.SMCOpen();
      double temp = cputemp.SMCGetTemperature(SMC_KEY_CPU_TEMP); 
      printf("%0.1f°C\n",temp);
      cputemp.SMCClose();

      std::cout << "REPLY TO " << interest.toUri() << std::endl;
      std::string content = std::to_string(temp) ; //"RELIABLE ECHO z";
    
      m_producer->produce(Name("z"), (uint8_t*)content.c_str(), content.size());
    }
    else
    {
      std::cout << "REPLY TO " << interest.toUri() << std::endl;
      std::string content = "RELIABLE ECHO zzz";
    
      m_producer->produce(Name("zzz"), (uint8_t*)content.c_str(), content.size());
    } 

    */
//    int sampleNumber =  std::stoi(interest.getName().get(-2).toUri());
//    std::cout << "Current Number" << std::dec << *m_curnum << std::endl;
//    if (sampleNumber > *m_curnum)
//    {
//      std::cout << "My NACK!!!!!!" << std::endl;
//      ApplicationNack appNack(interest, ApplicationNack::PRODUCER_DELAY);
//      appNack.setDelay(5000); // in ms
//      m_producer->nack(appNack);
//    }
//    std::cout << "NO HIT Interest!" << interest.getName().toUri() << std::endl;
//    std::cout << "HAHA " <<std::dec<< sampleNumber << std::endl;
  }
  
  void
  ProducerCallback::processIncomingInterest(const Interest& interest)
  {
    std::cout << "processIncomingInterest " << interest.getName() << std::endl;
  }
  
  void
  ProducerCallback::processOutgoingData(const Data& data)
  {
    std::cout << "OutgoingData " << data.getName() << std::endl;
//    Interest interestData = data.getName()
//    std::cout << data.wireEncode().wire() << std::endl;
//    std::cout << data.wireEncode().size() << std::endl;
//    std::cout << data.wireEncode().value_size() << std::endl;
//
//    boost::asio::io_service iosev;
//    boost::asio::ip::tcp::socket socket(iosev);
//    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::from_string("127.0.0.1"), 1000);
//    boost::system::error_code ec;
//    socket.connect(ep,ec);
//
//    if(ec)
//    {
//      std::cout << "error: " <<  boost::system::system_error(ec).what() << std::endl;
//    }
//    //Send data
//    socket.write_some(boost::asio::buffer(data.wireEncode().wire(), data.wireEncode().size()), ec);

//    std::cout << data.getContent().value() << std::endl;
//    std::cout << data.wireEncode().value() << std::endl;
//    std::cout << data.wireEncode().m_buffer.buf() << std::endl;
    
  //    std::cout << data.getFinalBlockId() << std::endl;
  }
 
  bool
  ProducerCallback::verifyInterest(Interest& interest){return true;}
  
  void
  ProducerCallback::processConstInterest(const Interest& interest){}

} // namespace ndn
