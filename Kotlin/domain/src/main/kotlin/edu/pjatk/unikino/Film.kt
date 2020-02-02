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
data class Film(val nazwa: String,
                val opis: String,
                val minWiek: Int,
                var sredniaOcena: Double)
{
    @OneToMany(mappedBy = "film", orphanRemoval = true, cascade = [CascadeType.REFRESH, CascadeType.DETACH, CascadeType.MERGE])
    @LazyCollection(LazyCollectionOption.FALSE)
    val seansy: MutableSet<Seans> = mutableSetOf()

    @Id
    @GeneratedValue
    private val id: Long? = null

    override fun toString(): String
    {
        return nazwa
    }
    
}