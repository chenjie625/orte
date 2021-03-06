/* DomainEvents.java */

/**
 * Class AppInfo. 
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

package org.ocera.orte.types;


public abstract class DomainEvents {
  /* handler to C struct with default domain properties  */
  private long handle = 0;


 /* load native library 'libjorte.so' */
  static {
     System.loadLibrary("jorte");
  }

  public DomainEvents()
  {
    this.handle = jORTEDomainInitEvents();
  	System.out.println(":j: events created & initialized..");
  }
  
  public long getHandle()
  {
  	return this.handle;
  }
  
  public boolean destroy()
  {
    System.out.println(":j: DomainEvents destroy called..");

    if(!jORTEDomainEventsDestroy(this.handle)) {
      System.out.println(":j: DomainEvents destroy fault!");
      return false;
    }
    else {
      System.out.println(":j: DomainEvents destroy successful..");
      return true;
    }
  }
  
  public abstract void onRegFail();
  public abstract void onMgrNew(AppInfo appInfo);
  public abstract void onMgrDelete(AppInfo appInfo);
  public abstract void onAppRemoteNew(AppInfo appInfo);
  public abstract void onAppDelete(AppInfo appInfo);
  public abstract void onPubRemoteNew(AppInfo appInfo, PubInfo pubInfo);
  public abstract void onPubRemoteChanged(AppInfo appInfo, PubInfo pubInfo);
  public abstract void onPubDelete(AppInfo appInfo, PubInfo pubInfo);
  public abstract void onSubRemoteNew(AppInfo appInfo, SubInfo subInfo);
  public abstract void onSubRemoteChanged(AppInfo appInfo, SubInfo subInfo);
  public abstract void onSubDelete(AppInfo appInfo, SubInfo subInfo);
  
 /* ****************************************************************** *
  *                                                                    *
  *                         native methods                             *
  *                                                                    *
  * ****************************************************************** */


 /**
  * jPropDefaultGet - returns handler to default properties of a domain,
  * if occures some error return NULL.
  *
  * @return handler to default properties of a domain, NULL if error
  */
  private native
  long jORTEDomainInitEvents();

  private native
  boolean jORTEDomainEventsDestroy(long handle);
}
