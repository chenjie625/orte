/* Domain.java */

/**
  * Class Domain provides methods for work with the ORTE domain.
  *
  * @author Lukas Pokorny (lukas_pokorny@centrum.cz)
  * @author CTU FEE Prague - Department of Control Engineering (dce.felk.cvut.cz)
  * @author Project ORTE - OCERA Real Time Ethernet (www.ocera.org)
  * @author dedication to Kj
  * @version 0.1
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  */

package org.ocera.orte;
import  org.ocera.orte.types.*;


public abstract class Domain {

   /** load native library 'libjorte.so' */
   static {
      System.loadLibrary("jorte");
   }

   /* domain fields */
   protected long			handle;
   protected long			domainEventsContextHandle = 0;
   protected DomainProp			props;
   protected DomainEvents		events;


   /* constructor */
   public Domain()
   {
     // initialization of ORTE layer
     JOrte.init();
     //System.out.println(":j: instance of 'Domain' created ..");
   }


  /**
   * Get handle of the Domain.
   * @return Handle of the Domain.
   */
   public long getHandle()
   {
     return this.handle;
   }

   /**
    * Destroy domain.
    * @return Handle of the Domain.
    */
    public abstract boolean destroy();
   
   
  /* ****************************************************************** *
   *                                                                    *
   *                         native methods                             *
   *                                                                    *
   * ****************************************************************** */

  /**
   * jORTEDomainStart -
   *
   * @param dhandle handler to domain
   * @param
   * @param
   * @return
   */
   private static native
   void jORTEDomainStart(long dhandle,
                         boolean recvMetatrafficThread,
                         boolean recvUserDataThread,
  	                     boolean sendThread);

}
