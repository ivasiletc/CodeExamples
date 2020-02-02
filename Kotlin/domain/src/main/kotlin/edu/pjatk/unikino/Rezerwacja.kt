package edu.pjatk.unikino

import javax.persistence.CascadeType
import javax.persistence.Entity
import javax.persistence.GeneratedValue
import javax.persistence.Id
import javax.persistence.ManyToOne

@Entity
class Rezerwacja(val miejsce: Int,
                 val rzad: Int,
                 val status: String,
                 val strefa: String,
                 @ManyToOne(cascade = [CascadeType.REFRESH, CascadeType.DETACH, CascadeType.MERGE])
                 val seans: Seans,
                 @ManyToOne(cascade = [CascadeType.MERGE])
                 val klient: Klient)
{
    
    
    @Id
    @GeneratedValue
    private val id: Long? = null
    
}