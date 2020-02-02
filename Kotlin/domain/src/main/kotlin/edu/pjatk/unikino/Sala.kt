package edu.pjatk.unikino

import org.hibernate.annotations.LazyCollection
import org.hibernate.annotations.LazyCollectionOption
import javax.persistence.CascadeType
import javax.persistence.Entity
import javax.persistence.GeneratedValue
import javax.persistence.Id
import javax.persistence.ManyToMany
import javax.persistence.ManyToOne
import javax.persistence.OneToMany

@Entity
data class Sala(val nazwa: String,
                val iloscMiejsc: Int,
                @ManyToOne(cascade = [CascadeType.REFRESH, CascadeType.DETACH, CascadeType.MERGE])
                val kinoteatr: Kinoteatr
                )
{
    @ManyToMany(mappedBy = "sala", cascade = [CascadeType.MERGE])
    @LazyCollection(LazyCollectionOption.FALSE)
    var seansy: MutableSet<Seans> = mutableSetOf()
    
    @Id
    @GeneratedValue
    private val id: Long? = null

    override fun toString(): String
    {
        return nazwa
    }
    
}